# craw_univ_ranking.py
import requests
import bs4
from bs4 import BeautifulSoup

def get_html_text(url):
    try:
        r = requests.get(url, timeout=30) # 30s
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ""

def fill_univ_list(ulist, html):
    soup = BeautifulSoup(html, "html.parser")
    for tr in soup.find('tbody').children:
        if isinstance(tr, bs4.element.Tag):
            tds = tr('td')
            ulist.append([tds[0].string, tds[1].string, tds[2].string])
    pass

def print_univ_list(ulist, num):
    tplt="{0:^10}\t{1:{3}^10}\t{2:^10}"
    print(tplt.format("排名", "学校名称", "总分", chr(12288))) # 当字符宽度不够时，系统默认采用西文字符填充，chr(12288)是中文空格
    for i in range(num):
        u = ulist[i]
        print(tplt.format(u[0], u[1], u[2], chr(12288)))

if __name__ == "__main__":
    uinfo = []
    url = 'http://www.zuihaodaxue.cn/zuihaodaxuepaiming2016.html'
    html = get_html_text(url)
    fill_univ_list(uinfo, html)
    print_univ_list(uinfo, 20)  # 20 univs
    
    