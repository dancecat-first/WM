#!python
import sys
import os
import requests
import time
from playsound import playsound 

def DownloadFile(mp3_url, save_url,file_name):
    try:
        if mp3_url is None or save_url is None or file_name is None:
            print('参数错误')
            return None
        # 文件夹不存在，则创建文件夹
        folder = os.path.exists(save_url)
        if not folder:
            os.makedirs(save_url)
        # 读取MP3资源
        res = requests.get(mp3_url,stream=True)
        # 获取文件地址
        file_path = os.path.join(save_url, file_name)
        #print('开始写入文件：', file_path)
        # 打开本地文件夹路径file_path，以二进制流方式写入，保存到本地
        with open(file_path, 'wb') as fd:
            for chunk in res.iter_content():
                fd.write(chunk)
        #print(file_name+' 成功下载！')
    except:
        print("程序错误")

#if __name__ == "__main__":
word=sys.argv[1]

# MP3源地址url
url = f'https://fanyi.baidu.com/gettts?lan=zh&text={word}&spd=5&source=web'
url_2=f'https://fanyi.sogou.com/reventondc/synthesis?text={word}&speed=1&lang=en&from=translateweb&speaker=1'
# MP3保存文件夹
save_url='music'
# MP3文件名
file_name = f'{word}.mp3'
file_name_2 = f'{word}2.mp3'
if os.path.exists(f"music/{word}.mp3") == False:
    DownloadFile(url,save_url, file_name)
if os.path.exists(f"music/{word}2.mp3") == False:
    DownloadFile(url_2,save_url, file_name_2)
playsound(f'music/{word}.mp3')
playsound(f'music/{word}2.mp3')