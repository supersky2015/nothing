﻿git is a distributed version control system.
git is free sofware. under the GPL.
工作区 版本库(暂存取stage 分支master)
git has a mutable index called stage.
git tracks changes of files.
//
创建SSH Key: ssh-keygen -t rsa -C "youremail@example.com"
git remote add origin git@github.com:xxxxxx/yyyyy.git    origin为远程库的名称，也可以改别的。
先拥有本地库，再建立跟远程库的连接。origin为远程库的名称。yyyyy.git为建立连接的远程库
git remote add dev git@github.com:xxxx/yyyy.git  dev为远程分支库名字。
git push -u origin master  把本地master分支的所有文件推送到远程库origin。
git remote rm origin	移除跟远程库origin的关联。
git push origin master	//把master分支推送到远程库origin
git push origin dev
git diff HEAD "XXX.TXT" 比较

git clone git@github.com:supersky2015/xxxx.git //用的ssh协议
先拥有远程库，再把远程库克隆到本地，跟本地库连接。
git clone https://github.com/supersky2015/xxxx.git	//用的https协议

git remote //查看远程库信息
git remote -v//查看远程库详细信息。

//
git checkout -b devname //创建分支并切换到分支
git branch devname //创建分支
git checkout dev //切换到分支
git branch//查看分支
git branch dev2
git merge dev //合并分支 默认Fast forward. 但这种模式下 ， 删除分支后 ，会丢掉分支信息。
git branch -d dev	//删除分支
git branch -D dev//强力删除 丢弃一个没有被合并的分支。

git log --graph --pretty=oneline --abbrev-commit	//查看合并分支情况 
git log
git log --pretty=oneline
git log --graph --pretty=oneline

git merge --no-ff -m "merge with no-ff" dev //Git 就会在 merge 时生成一个新的 commit ，这样 ，从分支历史上就可以看出分支信息。
git reset --hard HEAD^
git diff HEAD xx.txt

git stash	//存储当前工作现场
git stash list //查看存储的工作现场
git stash apply	//恢复现场。stash内容不删除；
git stash drop //删除现场
git stash pop 	//恢复现场，并删除stash内容；
git stash apply stash@{0}	//恢复指定现场。

 git push origin branch-name	//推送自己的修改
  git pull	//获取最新 
  如果 git pull 提示“no tracking information” ，则说明本地分支和远程分支的链接
关系没有创建，用命令 git branch --set-upstream-to branch-name origin/branch-name 。

//
PHP<a>标签传参数Url不能太长，否则会导致Ondrop无效。
just test another merge 
git process bug td001
