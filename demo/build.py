import sys
import os
import pathlib
from pathlib import Path
import shutil
import subprocess
import datetime
import pathlib


#change this include to reflect your configuration for the build
from config import *
#from proj_demo.config_proj import *
#from img.config_cimg import *
        
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
    
def main(argv):
         
    os.system("cls")
    
    if len(argv) < 2:
        print("Error missing parameters")
        return
    
    build_cmd = ""    
    type = argv[1]

    if type == "--project":
        
        print("------------------------------------------------------------------")
        print("Build parameters: {}".format(BUILD))
        print("Windows libraries linked: {}".format(LIB_WINDOWS))
        print("Include files: {}".format(INCLUDE))
        print("My library: {}".format(TEMPLATE_LIB))
        print("Sources: {}".format(SRC))
        print("------------------------------------------------------------------")
        
        if SRC == "":
            print("This option expects a list of sources")
            return
        build_cmd = BUILD + TEMPLATE_LIB + INCLUDE + SRC + LINK + LIB_WINDOWS
      
        print("Running {}".format(build_cmd))
        print("--------------------------------------------------------------")
        
        result = run_win_cmd(build_cmd)
        
        if result == 0:
            dir = os.getcwd()
            remove_files(dir,"obj")
           
            print("-------------------------------------------------------------")
    else:
        
        print("--------------------------------------------------------------")
        print("Build parameters: {}".format(BUILD))
        print("Windows libraries linked: {}".format(LIB_WINDOWS))
        print("Include files: {}".format(INCLUDE))
        print("My library: {}".format(TEMPLATE_LIB))
        print("Source: {}".format(argv[1] ))        
        print("--------------------------------------------------------------")
        
        build_cmd = BUILD + TEMPLATE_LIB + INCLUDE + argv[1] + LIB_WINDOWS
        
        print("Running {}".format(build_cmd))
        print("--------------------------------------------------------------")
        
        result = run_win_cmd(build_cmd)
        
        if result == 0:
            
            dir = os.getcwd()
            file_name, t = os.path.splitext(argv[1])
            remove_files(dir,"obj")        
            create_folder(dir,"out")
            move(file_name+".exe", dir+"\\out")        
            print("-------------------------------------------------------------")
                 
if __name__ == '__main__':
    
    main(sys.argv)  