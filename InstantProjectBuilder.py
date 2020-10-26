import os
#make sure Cmake is in PATH
proj = input("project name: ")

# main.cpp
f = open("\"" + proj + ".cpp\"", "w")
f.write("int main()\n{\n\t\n}")
f.close()

# Make "CmakeLists.txt"
f = open("CMakeLists.txt", "w")
f.write("cmake_minimum_required(VERSION 3.6)\n" + 
"project("+proj+")\n" +
"add_executable(app " + proj + ".cpp)\n"+
"set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT app)")
f.close()

#open .sln
os.system("cmake -S . -B ./build/")
path = "\""+os.getcwd()+"\\build\\"+proj+".sln\""
os.system(path)
