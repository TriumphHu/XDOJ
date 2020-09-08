package cn.itcast.travel.service;

public interface FavoriteService
{
    /**
     * 判断该用户是否收藏
     * @param rid
     * @param uid
     * @return
     */
    public boolean isFavorite(String rid, int uid);

    /**
     * 添加方法
     * @param rid
     * @param uid
     */
    void add(String rid, int uid);
}
