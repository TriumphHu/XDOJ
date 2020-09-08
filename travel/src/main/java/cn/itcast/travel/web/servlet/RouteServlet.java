package cn.itcast.travel.web.servlet;

import cn.itcast.travel.domain.PageBean;
import cn.itcast.travel.domain.Route;
import cn.itcast.travel.domain.User;
import cn.itcast.travel.service.FavoriteService;
import cn.itcast.travel.service.RouteService;
import cn.itcast.travel.service.impl.FavoriteServiceImpl;
import cn.itcast.travel.service.impl.RouteServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/route/*")
public class RouteServlet extends BaseServlet
{

    private RouteService routeService = new RouteServiceImpl();
    private FavoriteService favoriteService = new FavoriteServiceImpl();
    /**
     * 分页查询
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    public void pageQuery(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        System.out.println("pageQuery!!!");
        String currentPageStr = request.getParameter("currentPage");
        String pageSizeStr = request.getParameter("pageSize");
        String cidStr = request.getParameter("cid");
        String rname = request.getParameter("rname");
        rname = new String(rname.getBytes("iso-8859-1"),"utf-8");
        int cid = 0;
        if(cidStr != null && cidStr.length() > 0 && !"null".equals(cidStr))
        {
            cid = Integer.parseInt(cidStr);
        }
        int currentPage = 0;
        if(currentPageStr != null && currentPageStr.length() > 0)
        {
            currentPage = Integer.parseInt(currentPageStr);
        }
        else
        {
            currentPage = 1;
        }
        //每页显示条数
        int pageSize = 0;
        if(pageSizeStr != null && pageSizeStr.length() > 0)
        {
            pageSize = Integer.parseInt(pageSizeStr);
        }
        else
        {
            pageSize = 5;
        }
        //调用service方法查询条数
        PageBean<Route> pb = routeService.pageQuery(cid, currentPage, pageSize,rname);
        //将pageBean对象系列化为json返回
        writeValue(pb,response);
    }

    /**
     * 根据id查询一个旅游线路的详细信息
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    public void findOne(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        //1.接收id
        String rid = request.getParameter("rid");
        //2.调用service查询route对象
        Route route = routeService.findOne(rid);
        //3.转化为json写会客户端
        writeValue(route,response);
    }

    /**
     * 判断当前用户是否收藏过该线路
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    public void isFavorite(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        //1.获取当前线路id
        String rid = request.getParameter("rid");
        //2.获取user对象
        User user = (User) request.getSession().getAttribute("user");
        int uid;
        if(user == null)
        {
            uid = 0;
        }
        else
        {
            uid = user.getUid();
        }
        //3.调用FavoriteService进行查询
        boolean flag = favoriteService.isFavorite(rid, uid);
        //4.写回客户端
        writeValue(flag,response);
    }
    public void addFavorite(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        //1.获取当前线路id
        String rid = request.getParameter("rid");
        //2.获取user对象
        User user = (User) request.getSession().getAttribute("user");
        int uid;
        if(user == null)
        {
            return;
        }
        else
        {
            uid = user.getUid();
        }
        favoriteService.add(rid,uid);
    }

}
