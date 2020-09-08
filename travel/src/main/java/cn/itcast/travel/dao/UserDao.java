package cn.itcast.travel.dao;

import cn.itcast.travel.domain.User;

public interface UserDao
{
    /**
     * 根据用户名查询对象
     * @param username
     * @return
     */
    public User findByUsername(String username);

    /**
     * 保存对象
     * @param user
     */
    public void save(User user);

    /**
     * 根据用户code查询对象
     * @param code
     * @return
     */
    User findByCode(String code);

    /**
     * 更新激活状态
     * @param user
     */
    void updateStatus(User user);

    /**
     * 根据用户名和密码查询对象
     * @param username
     * @param password
     * @return
     */
    User findByUsernameAndPassword(String username, String password);
}
