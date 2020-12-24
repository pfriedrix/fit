#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <signal.h>
using namespace std;

void signal_callback_handler(int signum) {
   cout << "Caught signal " << signum << endl;
}
int main(){
   signal(SIGTSTP, signal_callback_handler);
    getchar();
}
