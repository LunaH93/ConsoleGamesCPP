# -*- coding: utf-8 -*-

from splinter import Browser
from time import sleep 

# 用户名和需要访问的地址等信息，暂时写死
username = u"576131032@qq.com"
password = u"hu993724xp"
startst = u"%u5317%u4EAC%2CBJP"
endst = u"%u767D%u57CE%2CBCT"
stime = u"2017-01-25"
passer = u"胡玥"
login_url = "https://kyfw.12306.cn/otn/login/init"
initmy_url = "https://kyfw.12306.cn/otn/index/initMy12306"
search_url = "https://kyfw.12306.cn/otn/leftTicket/init"

# 定义登陆模块
def login():
	b.fill(u"loginUserDTO.user_name",username)
	b.fill(u"userDTO.password",password)
	print u"等待输入验证码"
	b.find_by_id(u"loginSub").click()
	sleep(5)

# 定义查询模块
def search():
	b.cookies.add({"_jc_save_fromStation": startst})
	b.cookies.add({"_jc_save_toStation":endst})
	b.cookies.add({"_jc_save_fromDate": stime})
	b.reload()
	sleep(2)
	
# 这块预留给图片验证码模型

# 调用浏览器-判断登陆状态|登陆-查询-判断-下单
b = Browser("chrome")
b.visit(search_url)
search()

# 进入未完成订单付款
# b.find_by_id(u"link_4_NonComOrder").click()