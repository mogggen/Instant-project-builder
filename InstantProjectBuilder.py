with open("main.cpp", "w") as f:
  f.write("int main()\n{\n\t\n}")
with open("CMakeLists.txt", "w") as f:
  f.write("cmake_minimum_required(VERSION 3.6)\nadd_executable(app main.cpp)")
import os
os.system("cmake -S . -B ./build/")
path = "\""+os.getcwd()+"\\build\\Project.sln\""
os.system(path)
