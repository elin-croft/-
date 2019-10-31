# 学习记录
为了让自己坚持下去。。。希望能做到日更吧

本菜鸡卑微的学习中，请大佬勿喷😁

2019.10/31 day1 (github)

今年刚考上了软件工程的研究生。研一事情比较少就想自己学点东西
由于我以前时学电子信息工程的。。。所以对软件工程了解的比较少。前一段看到一篇机器之心里python从入门到精通的微信文章
里提到了github，然后就燃起了我本科时曾经有过的学习github的想法。

其实我在本科的时候用过一点github但是只会clone。。。
我之前用过的github都是当成网页浏览来使用了，完全没想到要在黑乎乎的终端里在上传项目
## 加入github
想要在github上托管项目肯定要先注册一个账号
然后我还按照官网的知道生成并绑定了ssh key

## 创建自己的第一个repo
右上角美美的头像旁边有个加号，点开就就可以选择New repository来创建一个repo
然后就是常规的命名(仅限字母)
最后选上初始化一个README.md
然后自己的第一个repo就创建好了

## 上传自己的项目
这时就要用到终端了
windows要下载git 由于某些原因我把我下载好的存到了毒盘里
链接: https://pan.baidu.com/s/1WewDMRp0OAL0MpEKJT9n5Q 
提取码: ert2
我由于之前装了linux子系统，所以就可以直接用ubuntu子系统来操作比较方便
我选择http地址clone下来然后在终端中进入刚才clone下来的文件夹
输入
    git config --global user.name "your name"
    git config --global user.email "your email"
用自己的用户名字和邮箱替换引号里的内容
>注意名字是名字，昵称是昵称，查看自己的profile 名字是头像下面小的那一行
然后用支持md文件的编辑器或者vim打开README.md编辑README.md文件并保存和退出
然后在项目文件下执行
git add .
或者运行git add REAM.md
第一个是添加所有当前路径下被修改的文件到暂存区，第二个是制定文件添加到暂存区
然后执行
git commit -m"whatever you want"自己随意更改引号里的内容
这样就可以把暂存区里改动的内容提交给本地版本库
然后就可以执行
git push
我看到好多人都在用,当然我也用过，但还没彻底理解
git push -u origin master
然后输入自己的用户名字和密码就可以push了
具体的参数设定我还在学习。。。
操作完之后就可以在github网站上对应的仓库中看到已经改变的README.md了

##　上传自己以前的cs231n assignment代码
从昨天开始上传自己以前做的cs231n的作业。。。
第一次在不知道的情况下用ssh clone了仓库
然后就用ssh key的密码完成了在github上的第一个push
然后开始上传以前的作业代码
然后遇到了好多问题。。。我有点记不清了。。。
印象最深的是不停的遇到"the remote end hung up unexpectedly"
然后改了postBuffer也没用，后来改了config的user.name。。。我第一次填了昵称😂
然后用莫名的出现了openssl的问题，google了后有大佬说要用opennssl重建git(当然我没有尝试)
然后受不了了就起的直接把clone下来的文件夹删了。。。
然后看到有人说用http，而且我还专程看了眼官方的介绍，官方也推荐http
所以我就用http clone下来了文件夹，然后试了好几次成功上传了作业。。。有时候断开网络连接再连上就能解决一些问题。。。
注意！上传的文件不能太大。。。我的作业3里有个2g多的coco所以我前几次死活上传不上去
ps. 没想到第一次编写md文件连二级标题都不到怎么标
    图片我现在还不会插入。。。以后在更新吧
