import requests
import os
url = "http://pic32.nipic.com/20130823/2501606_135441356000_2.jpg"
root = "D://pics//"
path = root + url.split('/')[-1]
try:
    if not os.path.exists(root):
        os.mkdir(root)
    if not os.path.exists(path):
        r = requests.get(url)
        with open(path, 'wb') as f:
            f.write(r.content)
            f.close()
            print("file saved")
    else:
        print("file already existed")
except:
    print("spider failed")