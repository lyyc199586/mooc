import requests
keyword = "Python" # 搜索关键字
try:
    kv = {'q': keyword}
    r = requests.get("http://www.so.com/s", params=kv)
    print(r.request.url) # 搜索网址格式：/s?q=keyword
    r.raise_for_status()
    print(len(r.text))
except:
    print("爬取失败")