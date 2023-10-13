import sys
import os
import pathlib
from pathlib import Path
import shutil
import subprocess
import datetime
import pathlib


#change this include to reflect your configuration for the build, EG:
#   from proj_demo.config_proj import *
#   from img.config_cimg import *

from config import *
        
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


def checklastchanged(file):

    filename = pathlib.Path(file)
    modify_timestamp = filename.stat().st_mtime
    print(modify_timestamp)
    

def build_single(build_cmd, src):

    build_cmd = build_cmd + " " + src
    print("-------------------------------------------------------------------------------------------------------------------------") 
    print("Running {}".format(build_cmd))
    print_build_info()
    print("-------------------------------------------------------------------------------------------------------------------------") 
    
    result = run_win_cmd(build_cmd)
    
    if result == 0:
        
        dir = os.getcwd()
        file_name, t = os.path.splitext(src)
        remove_files(dir,"obj")        
        create_folder(dir,"out")
        move(file_name+".exe", dir+"\\out")        
        print("-------------------------------------------------------------------------------------------------------------------------") 
        
def build_project(build_cmd):      
    
    print("-------------------------------------------------------------------------------------------------------------------------") 
    print("Running {}".format(build_cmd))
    print_build_info()
    print("-------------------------------------------------------------------------------------------------------------------------") 
    
    result = run_win_cmd(build_cmd)
    
    if result == 0:
        dir = os.getcwd()
        remove_files(dir,"obj")           
    
    print("-------------------------------------------------------------------------------------------------------------------------") 
            
    
def main(argv):
         
    os.system("cls")
    
    if len(argv) < 2:
        print("Error missing parameters")
        return
    
    build_cmd = ""    
    type = argv[1]

    if type == "--project":        
        build_project(BUILD_CMD)        
    else:
        build_single(BUILD_CMD,argv[1])
                 
if __name__ == '__main__':
    
    main(sys.argv)  