import os

myos = ""
while myos not in ["U", "W"]:
    myos = input("Are you using Windows or a Unix-like OS? [W/U] \n")

os.system("rm Makefile")

if myos == "U":
    os.system("cp Makefile.nix Makefile")
elif myos == "W":
    os.system("cp Makefile.win Makefile")

os.system("make clean")