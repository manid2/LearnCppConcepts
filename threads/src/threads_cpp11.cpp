/*
 * threads_cpp11.cpp
 *
 *  Created on: 25-Nov-2019
 *      Author: Mani Kumar
 */

#include <threads_cpp11.h>

namespace PFF {

std::mutex mu;
std::condition_variable cond;

int count = 1;

void PrintOdd(int num) {
  for (int i = 0; i < num; i++) {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker, []() {return (count%2 == 1);});
    cout << "Thread_A: " << count << endl;
    count++;
    locker.unlock();
    cond.notify_all();
  }
}

void PrintEven(int num) {
  for (int i = 0; i < num; i++) {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker, []() {return (count%2 == 0);});
    cout << "Thread_B: " << count << endl;
    count++;
    locker.unlock();
    cond.notify_all();
  }
}

} /* namespace PFF */
