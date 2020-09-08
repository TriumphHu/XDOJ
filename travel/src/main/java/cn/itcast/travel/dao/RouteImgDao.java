package cn.itcast.travel.dao;

import cn.itcast.travel.domain.RouteImg;

import java.util.List;

public interface RouteImgDao
{
    public List<RouteImg> findByRid(int rid);
}
