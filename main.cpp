#include <cstring>
//#include <stdio.h>
#include <iostream>
#include <fstream>

#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <pthread.h>
#include <thread>
#include <cmath>

long long
add_to_running_sum()
{
}

int
main(int argc, char** argv)
{
    for (size_t i = 1; i < argc; i++)
    {
        // system info
        if (!strcmp(argv[i], "-i"))
        {
            // number of processors
            std::cout << "Number of processors: " << get_nprocs() << std::endl;

            // hostname
            char hostname[256];
            if (gethostname(hostname, 256))
            {
                std::cerr << "Cannot find hostname";
                return 1;
            }
            std::cout << "hostname: " << hostname << std::endl;

            // Hardware platform
            utsname hardware_platform;
            uname(&hardware_platform);
            std::cout << "hardware platform: " << hardware_platform.machine << std::endl;
            
            std::string line;
            std::ifstream myfile("/proc/meminfo");
            if (myfile.is_open())
            {
                if (getline (myfile,line))
                {
                    std::cout << line << '\n';
                }
                myfile.close();
            }
            else
            {
                std::cout << "Unable to open file";
            }
            continue; // becuase I don't trust myself :D
        }

        // running sum
        if (i + 1 >= argc)
        {
            std::cerr << "X was not given! Exiting..." << std::endl;
            return 1;
        }
        int X;
        try
        {
            X = std::stoi(argv[i + 1]);
        }
        catch (std::exception& e)
        {
            printf("%s() raised a type exception: argument \"%s\" could not be parsed to a integer!\n", e.what(), argv[i + 1]);
            return 1;
        }
        
        uint running_sum = 0;
        for (size_t i = 0; i < X; i++)
        {
            int p0;
            if (!strcmp(argv[i], "-f"))
            {
                fork();
                if (p0)
                {
                    printf("thread-process-id %5i\n", p0);
                }
            }
            else if (!strcmp(argv[i], "-t"))
            {
                std::thread worker(add_to_running_sum);
                std::cout << ((std::thread::id*)&(worker.get_id())) << std::endl;
                worker.detach();
                if (p0)
                {
                    printf("fork-process-id %5i\n", p0);
                }
            }
            running_sum += p0;
        }

        // loop and sum
        double loop_sum = 0;
        for (size_t i = 1; i < 50000; i++)
        {
            for (size_t j = 1; j < i; j++)
            {
                loop_sum += sqrt(i * j);
            }
        }
        printf("the resulting sum is %i", loop_sum);
    }
    return 0;
} // int main
