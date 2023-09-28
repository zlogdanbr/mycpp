import sys
import os
import pathlib
from pathlib import Path
import shutil
import subprocess

BUILD   =  "cl "  
LINK    = " /link"

        
def run_win_cmd(cmd):
    
    result = subprocess.call(cmd, shell = True)
    return result

def getextension(file):

    return pathlib.Path(file).suffix[1:]
 

def move(src,dst):

    if os.path.isdir(dst):
        dst = os.path.join(dst, os.path.basename(src))
    shutil.move(src, dst)   

def create_folder( dir_root, name ):
    
    full_path = dir_root + "\\" + name
    if os.path.exists(full_path) == False:
        os.mkdir(full_path)
    else:
        return ""
    return full_path
    
    
def remove_files(dir,ext):

    for root, dirs, files in os.walk(dir):
        for name in files:
            fext = getextension(name)
            full = "{}\{}".format(root,name)
            if fext == ext:                
                if os.path.isfile(full):
                    print("removing {}".format(full))
                    os.remove(full)    

def concat( argv ):
    o = ""
    for f in argv:
        o = f + " " + o 
    return o
    
def main(argv):
           
    build_cmd = []

    if ( len(argv) > 2 ):
        str = concat(argv[1:])
        build_cmd.append(BUILD)
        build_cmd.append( OPTIONS + INCLUDES + LIB + str )
        build_cmd.append(LINK)
    else:
        build_cmd = BUILD + "%BUILD_ME% " + argv[1]
    
    print("Running {}".format(build_cmd))
    result = run_win_cmd(build_cmd)
    
    if result == 0:
        
        dir = os.getcwd()
        remove_files(dir,"obj")
        file_name, t = os.path.splitext(argv[1])
        create_folder(dir,"out")
        move(file_name+".exe", dir+"\\out")
                 
if __name__ == '__main__':
    main(sys.argv)  