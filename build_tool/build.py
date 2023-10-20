import sys
import os
import pathlib
from pathlib import Path
import shutil
import subprocess
import datetime
import pathlib


from config import *
        
def run_win_cmd(cmd):
    
    result = subprocess.call(cmd, shell = True)
    return result
    
def add_source_to_cmd(cmd, actual_src ):
    str =  cmd.replace("%%SRC%%",actual_src)
    return str
    

def build_single(build_cmd, src):

    build_cmd_effective = add_source_to_cmd(build_cmd,src)
    print("-------------------------------------------------------------------------------------------------------------------------") 
    print("Running {}".format(build_cmd_effective))
    print("-------------------------------------------------------------------------------------------------------------------------") 
    
    result = run_win_cmd(build_cmd_effective)

        
            
    
def main(argv):
         
    print(argv[1])
        
    build_single(BUILD_CMD,argv[1])       
        
        
                 
if __name__ == '__main__':
    
    main(sys.argv)  