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
                throw 0;
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
            //proc/meminfo
        }

        if (!strcmp(argv[i], "-F"))
        {
            // running sum
            if (true)//std::__is_integer<char*>(argv[i + 1]))
            {
                int X = std::stoi(argv[i + 1]);
                for (size_t i = 0; i < X; i++)
                {
                    //Threads summing
                    fork();
                }
                
            }
            else
            {
                std::cerr << "X was not an integer! Exiting..." << std::endl;
            }
            }
            else
            {
                std::cerr << "X was not given! Exiting..." << std::endl;
                return 1;
            }
        }
        
        if (!strcmp(argv[i], "-t"))
        {
            //system("top");

        }
    }

    return 0;
}