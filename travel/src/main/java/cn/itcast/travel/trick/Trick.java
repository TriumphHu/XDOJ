package cn.itcast.travel.trick;

import cn.itcast.travel.util.MailUtils;

public class Trick
{
    public static void main(String[] args)
    {
        String email = "hxssr520@163.com";
        String content = "<a href = 'https://www.baidu.com/baidu?wd=4399&tn=monline_4_dg&ie=utf-8'>点击进入大_人_的世界,⁄(⁄ ⁄•⁄ω⁄•⁄ ⁄)⁄</a>";
        for (int i = 0; i < 10; i++)
            MailUtils.sendMail(email,content,"宝贝爱你哟！！");
        System.out.println("发送完成");
    }

}
