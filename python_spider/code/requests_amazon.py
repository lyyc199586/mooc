# requests_amazon.py
import requests
url = "https://www.amazon.cn/gp/product/B01M8L5Z3Y"
try:
    kv = {'user-agent': 'Mozilla/5.0'} # 通过人为设定头部信息绕过亚马逊的来源审查
    r = requests.get(url, headers=kv)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[1000:2000])
except:
    print("爬取失败")