package cn.itcast.travel.service.impl;

import cn.itcast.travel.dao.UserDao;
import cn.itcast.travel.dao.impl.UserDaoImpl;
import cn.itcast.travel.domain.User;
import cn.itcast.travel.service.UserService;
import cn.itcast.travel.util.MailUtils;
import cn.itcast.travel.util.UuidUtil;

public class UserServiceImpl implements UserService
{

    private UserDao userDao = new UserDaoImpl();
    /**
     * 注册方法
     * @param user
     * @return
     */
    @Override
    public boolean regist(User user)
    {
        //调用dao方法查询用户名是否存在
        User u = userDao.findByUsername(user.getUsername());
        if(u != null)
        {
            //u不为null证明用户名已经存在了
            return false;
        }
        //设置激活码
        user.setCode(UuidUtil.getUuid());
        //设置激活状态
        user.setStatus("N");

        userDao.save(user);
        //设置邮件正文
        String content = "<a href='http://localhost/travel/user/active?code="+user.getCode()+"'>点击激活《黑马旅游网》</a>";

        //发送邮件
        MailUtils.sendMail(user.getEmail(),content,"激活邮件");
        return true;
    }

    @Override
    public boolean active(String code)
    {
        //根据用户code查询用户
        User user = userDao.findByCode(code);
        if(user != null)
        {
            //调用Dao更改用户激活状态
            userDao.updateStatus(user);
            return true;
        }
        return false;
    }

    @Override
    public User login(User user)
    {
        return userDao.findByUsernameAndPassword(user.getUsername(),user.getPassword());
    }
}
