git is a distributed version control system.
git is free sofware. under the GPL.
工作区 版本库(暂存取stage 分支master)
git has a mutable index called stage.
git tracks changes of files.
//
创建SSH Key: ssh-keygen -t rsa -C "youremail@example.com"
git remote add origin git@github.com:xxxxxx/yyyyy.git    origin为远程库的名称，也可以改别的。
git push -u origin master  把本地master分支的所有文件推送到远程库origin。
git remote rm origin	移除跟远程库origin的关联。
git push origin master
git diff HEAD "XXX.TXT"
//