#!python
import sys
import os
import requests
from playsound import playsound   
import time

#if __name__ == "__main__":
word=sys.argv[1]

# MP3保存文件夹
save_url='music'
# MP3文件名
file_name = f'{word}.mp3'
file_name_2 = f'{word}2.mp3'
playsound(f'music/{word}.mp3')
playsound(f'music/{word}2.mp3')