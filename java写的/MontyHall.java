import java.util.Date;
import java.util.Random;
import java.util.Scanner;

public class MontyHall
{
    public static void main(String[] args)
    {
        int i,player,choose; //i是哪扇门后面有车，player是选手选的门,result为正确的结果次数,choose来选择是否换门，换则为1不换则0
        int result = 0;
        double times = 10000; //定义运行多少次
        int []arr = new int[3];
        Date date = new Date();
        Random random = new Random(date.getTime()); //取得当前时间来设定种子值，使得每次更随机

        Scanner sc = new Scanner(System.in);
        System.out.println("美国的一个电规游戏节目Let‘s Make a Deal上有一个游戏，规则如下：参赛者会看\n" +
                "见三扇关闭了的门，其中一扇的后面有一辆汽车，选中后面有车的那扇门就可以赢得\n" +
                "该汽车，而另外两扇门后面则各藏有一只山羊。当参赛者选定了一扇门，但未去开启\n" +
                "它的时候，节目主持人会开启剩下两扇门的其中一扇，露出其中一只山羊。主持人其\n" +
                "后会问参赛者要不要换另一扇仍然关上的门。");
        System.out.println("----------------------------华丽的分割线-------------------------------");
        System.out.println("请问选手你是否要换门，换则输入1，不换则输入0");
        choose = sc.nextInt();
        for(int n = 0; n < times; n++)
        {
            i = random.nextInt(3);
            player = random.nextInt(3);
            arr[i] = 1;                 //通过随机数给门后赋值，为1即为车

            //现在进行选手不换门操作
            if (choose == 0)
            {
                if(arr[player] == 1)
                {
                    result++;
                }
            }
            //现在选手进行换门
            if (choose == 1)
            {
                if(arr[player] != 1)
                {
                    result++;
                }
            }

            arr[i] = 0; //使原来车的位置为0，重新洗牌

        }
        System.out.println("实验进行了 "+ times +" 次，选中车的概率为 "+result/times);

    }
}
