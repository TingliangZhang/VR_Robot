import re, urllib.request
def url_extract(homepage):
    regex_href = re.compile(r'href="(.+?)"')
    f = urllib.request.urlopen(homepage)
    webcontents = f.read().decode()
    matches = regex_href.finditer(webcontents)
    for m in matches:
        print(m.group(1))
#测试代码
if __name__=='__main__':
    www = r'http://www.baidu.com'
    url_extract(www)
