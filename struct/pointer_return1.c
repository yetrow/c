#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#define EXP_PER_LEVEL 100  //每级所需经验值
#define MAX_LEVEL 10
#define HINTS_COUNT 10   //宝藏的数量

void increasing_exp(int32_t* exp, int32_t exp_value);
bool check_level_up(int32_t* exp, int32_t* player_level);
const char* get_hints(int32_t level);


int main(void)
{

    /*游戏概念

    玩家属性：exp，level
    揭秘
    等级提升
    游戏目标
    */
    int32_t player_exp = 0;
    int32_t player_level = 1;

    //模拟玩家解密获得经验值
    increasing_exp(&player_exp, 50);
    //检查
    if (check_level_up(&player_exp, &player_level)) {
        printf("当前经验值：%d\n", player_exp);
        printf("当前等级：%d\n", player_level);
        printf("当前宝箱：%s\n", get_hints(player_level));
    }
    else {
        printf("还需要更多经验升级\n");
    }


    return 0;
}


void increasing_exp(int32_t* exp, int32_t exp_value)
{
    *exp += exp_value;
}

bool check_level_up(int32_t* exp, int32_t* player_level)
{
    while (*exp >= EXP_PER_LEVEL && *player_level < MAX_LEVEL) {
        *exp -= EXP_PER_LEVEL;
        (*player_level)++;
        printf("恭喜你升级到了%d级\n", *player_level);
        if (*player_level == MAX_LEVEL) {
            printf("你已经达到最高等级%d级\n", MAX_LEVEL);
            return false;
        }
    }

}

const char* get_hints(int32_t level)
{
    static const char* hints[HINTS_COUNT] = {
        "提示1：寻找隐藏的宝藏",
        "提示2：解锁新的技能",
        "提示3：与其他玩家合作",
        "提示4：完成每日任务",
        "提示5：参加限时活动",
        "提示6：探索未知区域",
        "提示7：收集特殊道具",
        "提示8：挑战强大的敌人",
        "提示9：参与公会活动",
        "提示10：获取成就奖励"
    };
    if (level<1 || level>MAX_LEVEL) {
        return "无效的等级";
    }
    return hints[level - 1];
}