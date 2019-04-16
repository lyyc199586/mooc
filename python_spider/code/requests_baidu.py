import requests
keyword = "Python"
try:
    kv = {'wd': keyword}
    r = requests.get("http://www.baidu.com/s", params=kv)
    print(r.request.url) # 搜索网址格式：/s?wd=keyword
    r.raise_for_status()
    print(len(r.text))
except:
    print("爬取失败")