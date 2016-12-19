import urllib2  
response = urllib2.urlopen('https://movie.douban.com/subject/26416603/?from=showing')  
html = response.read()
print html.decode("UTF-8")