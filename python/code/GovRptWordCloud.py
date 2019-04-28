# GovRptWordCloud.py
import jieba
import wordcloud
from scipy.misc import imread
#mask = imread("fivestar.png") # 蒙板要求背景为白色
mask = imread("chinamap.jpg")
f = open("新时代中国特色社会主义.txt", "r", encoding="utf-8")
t = f.read()
f.close()
ls = jieba.lcut(t)
txt = " ".join(ls)
w = wordcloud.WordCloud(font_path="msyh.ttc",
                        width=1000, height=700, background_color="white",
                        mask=mask,
                        #max_words=15
                        )
w.generate(txt)
w.to_file("grwordcloud1.png")