package cn.itcast.travel.service.impl;

import cn.itcast.travel.dao.CategoryDao;
import cn.itcast.travel.dao.impl.CategoryDaoImpl;
import cn.itcast.travel.domain.Category;
import cn.itcast.travel.service.CategoryService;
import cn.itcast.travel.util.JedisUtil;
import redis.clients.jedis.Jedis;
import redis.clients.jedis.Tuple;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public class CategoryServiceImpl implements CategoryService
{
    private CategoryDao categoryDao = new CategoryDaoImpl();
    @Override
    public List<Category> findAll()
    {
        //1.从redis查询
        //1.1从jedis获取客户端
        Jedis jedis = JedisUtil.getJedis();
        //1.2使用sortedset排序查询
        //Set<String> categorys = jedis.zrange("category", 0, -1);
        Set<Tuple> categorys = jedis.zrangeWithScores("category", 0, -1);
        List<Category> cs = null;
        //2.判断查询的集合是否为空
        if(categorys == null || categorys.size() == 0)
        {
            System.out.println("从数据库查询");
            //3.如果为空，从数据库进行查询
            cs = categoryDao.findAll();
            //将数据存入缓存
            for(int i = 0; i < cs.size(); i++)
            {
                jedis.zadd("category",cs.get(i).getCid(),cs.get(i).getCname());
            }
        }
        else
        {
            System.out.println("从缓存查询");
            //4.如果不为空，将set转换为List
            cs = new ArrayList<Category>();
            for (Tuple tuple : categorys)
            {
                Category category = new Category();
                category.setCname(tuple.getElement());
                category.setCid((int)tuple.getScore());
                cs.add(category);
            }
        }
        return cs;
    }
}
