import requests
url = "http://m.ip138.com/ip.asp?ip=" # 这个网站可以返回ip地址来源
try:
    r = requests.get(url + '202.204.80.112')
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[-500:])
except:
    print("spider filed")

