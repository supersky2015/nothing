git is a distributed version control system.
git is free sofware. under the GPL.
工作区 版本库(暂存取stage 分支master)
git has a mutable index called stage.
git tracks changes of files.
//
创建SSH Key: ssh-keygen -t rsa -C "youremail@example.com"
git remote add origin git@github.com:xxxxxx/yyyyy.git    origin为远程库的名称，也可以改别的。
先拥有本地库，再建立跟远程库的连接。origin为远程库的名称。yyyyy.git为建立连接的远程库
git push -u origin master  把本地master分支的所有文件推送到远程库origin。
git remote rm origin	移除跟远程库origin的关联。
git push origin master
git diff HEAD "XXX.TXT" 比较

git clone git@github.com:supersky2015/xxxx.git //用的ssh协议
先拥有远程库，再把远程库克隆到本地，跟本地库连接。
git clone https://github.com/supersky2015/xxxx.git	//用的https协议

//
git checkout -b devname //创建分支并切换到分支
git branch devname //创建分支
git checkout dev //切换到分支
git branch//查看分支
git branch dev2
git merge dev //合并分支 默认Fast forward. 但这种模式下 ， 删除分支后 ，会丢掉分支信息。
git branch -d dev	//删除分支

git log --graph --pretty=oneline --abbrev-commit	//查看合并分支情况 
git log
git log --pretty=oneline
git log --graph --pretty=oneline

git merge --no-ff -m "merge with no-ff" dev //Git 就会在 merge 时生成一个新的 commit ，这样 ，从分支历史上就可以看出分支信息。
git reset --hard HEAD^
git diff HEAD xx.txt
//
PHP<a>标签传参数Url不能太长，否则会导致Ondrop无效。
just test another merge 
git process bug td001
