# CrawTaobaoPrice.py
import requests
import re

def getHTMLText(url):
    kv = {'cookie': 'UM_distinctid=16966f73b9c92-0e1ef9d04aa34d-9333061-130980-16966f73b9f247; cna=GAL1FEqHCGECAcp4CxidRAEd; t=50da27c864867d86f6b95e341f077953; cookie2=18ef6049d1ab7e9ca4e65893a11fa108; v=0; _tb_token_=386e3353395b; unb=1890241226; sg=667; _l_g_=Ug%3D%3D; skt=58c2dd14d8b26c46; cookie1=AQYPFQnzEbfRUeXuy3XCOV5UcuwY9rZv3DcqqcWopOQ%3D; csg=59c96a9f; uc3=vt3=F8dByEfOW338S%2FG8xw0%3D&id2=UonSehbNFPgNEg%3D%3D&nk2=D9rrmnw683VZIQ%3D%3D&lg2=V32FPkk%2Fw0dUvg%3D%3D; existShop=MTU1NTk0NTYwMg%3D%3D; tracknick=lyyc199586; lgc=lyyc199586; _cc_=UtASsssmfA%3D%3D; dnk=lyyc199586; _nk_=lyyc199586; cookie17=UonSehbNFPgNEg%3D%3D; tg=0; enc=CoIO5W66Vulf1Xml1nHWxsFCJ8pcTAh3KZCgLh4hGAPSUBPKf1rqnChNumCrXwBzkIE92ZIo2GjcvNLsaBp8yg%3D%3D; hng=CN%7Czh-CN%7CCNY%7C156; thw=cn; uc1=cookie16=UIHiLt3xCS3yM2h4eKHS9lpEOw%3D%3D&cookie21=W5iHLLyFeYZ1WM9hVnmS&cookie15=Vq8l%2BKCLz3%2F65A%3D%3D&existShop=false&pas=0&cookie14=UoTZ4Sw1rO0Emw%3D%3D&tag=8&lng=zh_CN; mt=ci=10_1; swfstore=283412; x=e%3D1%26p%3D*%26s%3D0%26c%3D0%26f%3D0%26g%3D0%26t%3D0%26__ll%3D-1%26_ato%3D0; JSESSIONID=985401E1544B7D904F7220200B631ECA', 'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36'}  # kv:登陆信息
    try:
        r = requests.get(url, headers=kv, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        #print(r.text[:1000]) # 查看爬取到的页面
        return r.text
    except:
        return ""

def parsePage(ilt, html):
    try:
        plt = re.findall(r'\"view_price\"\:\"[\d\.]*\"',html)
        tlt = re.findall(r'\"raw_title\"\:\".*?\"',html)
        for i in range(len(plt)):
            price = eval(plt[i].split(':')[1])
            title = eval(tlt[i].split(':')[1])
            ilt.append([price , title])
    except:
        print("")

def printGoodsList(ilt):
    tplt = "{:4}\t{:8}\t{:16}"
    print(tplt.format("序号", "价格", "商品名称"))
    count = 0
    for g in ilt:
        count = count + 1
        print(tplt.format(count, g[0], g[1]))

def main():
    goods = '书包'
    depth = 2 # 搜索深度
    start_url = 'https://s.taobao.com/search?q=' + goods
    infoList = []
    for i in range(depth):
        try:
            url = start_url + '&s=' + str(44 * i) 
            html = getHTMLText(url)
            parsePage(infoList, html)
        except:
            continue
    printGoodsList(infoList)

main()