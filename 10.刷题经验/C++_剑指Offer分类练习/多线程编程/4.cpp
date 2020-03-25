/*
，题目大意如下：有一个写者很多读者，
多个读者可以同时读文件，
但写者在写文件时不允许有读者在读文件，
同样有读者读时写者也不能写。
*/

#include <iostream>  
#include <string>  
#include  <thread>  
#include  <mutex>
#include <condition_variable>

using namespace std;


class rwlock {
private:
    mutex _lock;
    condition_variable _wcon, _rcon;
    unsigned _writer, _reader;
    int _active;
public:
    void read_lock() {
        unique_lock<mutex> lock(_lock);
        ++_reader;
        while (_active < 0 || _writer > 0)
            _rcon.wait(lock);
        --_reader;
        ++_active;
    }
    void write_lock() {
        unique_lock<mutex> lock(_lock);
        ++_writer;
        while (_active != 0)
            _wcon.wait(lock);
        --_writer;
        _active = -1;
    }
    void unlock() {
        unique_lock<mutex> lock(_lock);
        if (_active > 0) {
            --_active;
            if (_active == 0) _wcon.notify_one();
        }
        else {
            _active = 0;
            if (_writer > 0) _wcon.notify_one();
            else if (_reader > 0) _rcon.notify_all();
        }

    }
    rwlock() :_writer(0), _reader(0), _active(0) {
    }
};

void t1(rwlock* rwl) {
    while (1) {
        cout << "I want to write." << endl;
        rwl->write_lock();
        cout << "writing..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        rwl->unlock();
        this_thread::sleep_for(chrono::seconds(5));
    }
}

void t2(rwlock* rwl) {
    while (1) {
        cout << "t2-I want to read." << endl;
        rwl->read_lock();
        cout << "t2-reading..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        rwl->unlock();
    }
}

void t3(rwlock* rwl) {
    while (1) {
        cout << "t3-I want to read." << endl;
        rwl->read_lock();
        cout << "t3-reading..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        rwl->unlock();
    }
}

int main()
{
    rwlock* rwl = new rwlock();
    thread th1(t1, rwl);
    thread th2(t2, rwl);
    thread th3(t3, rwl);
    th1.join();
    th2.join();
    th3.join();

    system("pause");
    return 0;
}