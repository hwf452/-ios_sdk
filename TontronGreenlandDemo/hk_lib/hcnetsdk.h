#ifndef _HC_NET_SDK_H_
#define _HC_NET_SDK_H_


#ifdef __cpluscplus
#define NET_DVR_API extern
#else
#define NET_DVR_API
#endif


#ifdef __cplusplus
extern "C"
{
#endif

#ifndef __PLAYRECT_defined
#define __PLAYRECT_defined
typedef struct __PLAYRECT {
    int x;
    int y;
    int uWidth;
    int uHeight;
} PLAYRECT;
#endif

#ifndef __HWND_defined
#define __HWND_defined
typedef void *HWND;
#endif

typedef struct tagInitInfo {
    int uWidth;
    int uHeight;
} INITINFO;


typedef uint32_t DWORD;
typedef uint16_t WORD;
typedef uint16_t USHORT;
typedef unsigned char BYTE;
typedef int32_t LONG;

typedef uint32_t UINT;
typedef void *LPVOID;
typedef void *HANDLE;
typedef uint32_t *LPDWORD;
typedef uint16_t *LPWORD;

#define    TRUE    1
#define        FALSE    0
#define     __stdcall
#define     CALLBACK

//宏定义
//宏定义
#define MAX_NAMELEN                16        //DVR本地登陆名
#define NAME_LEN                32      //用户名长度
#define PASSWD_LEN                16      //密码长度
#define SERIALNO_LEN            48      //序列号长度
#define MACADDR_LEN                6       //mac地址长度
#define MAX_ETHERNET            2       //设备可配以太网络
#define PATHNAME_LEN            128     //路径长度
#define MAX_PRESET_V13          16      //预置点
#define MAX_DOMAIN_NAME            64        /* 最大域名长度 */

#define MAX_TIMESEGMENT_V30        8       //9000设备最大时间段数
#define MAX_TIMESEGMENT            4       //8000设备最大时间段数

#define MAX_SHELTERNUM            4       //8000设备最大遮挡区域数
#define MAX_DAYS                7       //每周天数
#define PHONENUMBER_LEN            32      //pppoe拨号号码最大长度

#define MAX_DISKNUM_V30            33        //9000设备最大硬盘数/* 最多33个硬盘(包括16个内置SATA硬盘、1个eSATA硬盘和16个NFS盘) */
#define MAX_DISKNUM                16      //8000设备最大硬盘数
#define MAX_DISKNUM_V10            8       //1.2版本之前版本

#define MAX_USERNUM_V30            32      //9000设备最大用户数
#define MAX_USERNUM                16      //8000设备最大用户数
#define MAX_EXCEPTIONNUM_V30    32      //9000设备最大异常处理数
#define MAX_EXCEPTIONNUM        16      //8000设备最大异常处理数
#define MAX_LINK                6       //8000设备单通道最大视频流连接数

#define MAX_STRINGNUM_V30        8        //9000设备最大OSD字符行数数
#define MAX_STRINGNUM            4       //8000设备最大OSD字符行数数
#define MAX_STRINGNUM_EX        8       //8000定制扩展
#define MAX_AUXOUT_V30            16      //9000设备最大辅助输出数
#define MAX_AUXOUT                4       //8000设备最大辅助输出数
#define MAX_HD_GROUP            16      //9000设备最大硬盘组数
#define MAX_NFS_DISK            8       //8000设备最大NFS硬盘数

#define MAXPROGRESS                100     //回放时的最大百分率
#define MAX_SERIALNUM            2       //8000设备支持的串口数 1-232， 2-485
#define CARDNUM_LEN                20      //卡号长度
#define MAX_VIDEOOUT_V30        4       //9000设备的视频输出数
#define MAX_VIDEOOUT            2       //8000设备的视频输出数

#define MAX_PRESET_V30                256        /* 9000设备支持的云台预置点数 */
#define MAX_TRACK_V30                256        /* 9000设备支持的云台轨迹数 */
#define MAX_CRUISE_V30                256        /* 9000设备支持的云台巡航数 */
#define MAX_PRESET                    128        /* 8000设备支持的云台预置点数 */
#define MAX_TRACK                    128        /* 8000设备支持的云台轨迹数 */
#define MAX_CRUISE                    128        /* 8000设备支持的云台巡航数 */

#define CRUISE_MAX_PRESET_NUMS        32        /* 一条巡航最多的巡航点 */

#define MAX_AUDIO                    1       //8000语音对讲通道数
#define MAX_AUDIO_V30                2       //9000语音对讲通道数
#define MAX_CHANNUM                    16      //8000设备最大通道数
#define MAX_ALARMIN                    16      //8000设备最大报警输入数
#define MAX_ALARMOUT                4       //8000设备最大报警输出数

#define MAX_ANALOG_CHANNUM          32      //最大32个模拟通道
#define MAX_ANALOG_ALARMOUT         32      //最大32路模拟报警输出
#define MAX_ANALOG_ALARMIN          32      //最大32路模拟报警输入

#define MAX_IP_DEVICE               32      //允许接入的最大IP设备数
#define MAX_IP_DEVICE_V40           64      //允许接入的最大IP设备数 最多可添加64个 IVMS 2000等新设备
#define MAX_IP_CHANNEL              32      //允许加入的最多IP通道数
#define MAX_IP_ALARMIN              128     //允许加入的最多报警输入数
#define MAX_IP_ALARMOUT             64      //允许加入的最多报警输出数


/* 最大支持的通道数 最大模拟加上最大IP支持 */
#define MAX_CHANNUM_V30               ( MAX_ANALOG_CHANNUM + MAX_IP_CHANNEL )//64
#define MAX_ALARMOUT_V30              ( MAX_ANALOG_ALARMOUT + MAX_IP_ALARMOUT )//96
#define MAX_ALARMIN_V30               ( MAX_ANALOG_ALARMIN + MAX_IP_ALARMIN )//160

/*******************全局错误码 begin**********************/
#define NET_DVR_NOERROR                    0    //没有错误
#define NET_DVR_PASSWORD_ERROR                1    //用户名密码错误
#define NET_DVR_NOENOUGHPRI                2    //权限不足
#define NET_DVR_NOINIT                        3    //没有初始化
#define NET_DVR_CHANNEL_ERROR                4    //通道号错误
#define NET_DVR_OVER_MAXLINK                5    //连接到DVR的客户端个数超过最大
#define NET_DVR_VERSIONNOMATCH                6    //版本不匹配
#define NET_DVR_NETWORK_FAIL_CONNECT        7    //连接服务器失败
#define NET_DVR_NETWORK_SEND_ERROR            8    //向服务器发送失败
#define NET_DVR_NETWORK_RECV_ERROR            9    //从服务器接收数据失败
#define NET_DVR_NETWORK_RECV_TIMEOUT        10    //从服务器接收数据超时
#define NET_DVR_NETWORK_ERRORDATA            11    //传送的数据有误
#define NET_DVR_ORDER_ERROR                    12    //调用次序错误
#define NET_DVR_OPERNOPERMIT                13    //无此权限
#define NET_DVR_COMMANDTIMEOUT                14    //DVR命令执行超时
#define NET_DVR_ERRORSERIALPORT                15    //串口号错误
#define NET_DVR_ERRORALARMPORT                16    //报警端口错误
#define NET_DVR_PARAMETER_ERROR            17  //参数错误
#define NET_DVR_CHAN_EXCEPTION                18    //服务器通道处于错误状态
#define NET_DVR_NODISK                        19    //没有硬盘
#define NET_DVR_ERRORDISKNUM                20    //硬盘号错误
#define NET_DVR_DISK_FULL                    21    //服务器硬盘满
#define NET_DVR_DISK_ERROR                    22    //服务器硬盘出错
#define NET_DVR_NOSUPPORT                    23    //服务器不支持
#define NET_DVR_BUSY                        24    //服务器忙
#define NET_DVR_MODIFY_FAIL                    25    //服务器修改不成功
#define NET_DVR_PASSWORD_FORMAT_ERROR        26    //密码输入格式不正确
#define NET_DVR_DISK_FORMATING                27    //硬盘正在格式化，不能启动操作
#define NET_DVR_DVRNORESOURCE                28    //DVR资源不足
#define    NET_DVR_DVROPRATEFAILED                29  //DVR操作失败
#define NET_DVR_OPENHOSTSOUND_FAIL            30  //打开PC声音失败
#define NET_DVR_DVRVOICEOPENED                31  //服务器语音对讲被占用
#define    NET_DVR_TIMEINPUTERROR                32  //时间输入不正确
#define    NET_DVR_NOSPECFILE                    33  //回放时服务器没有指定的文件
#define NET_DVR_CREATEFILE_ERROR            34    //创建文件出错
#define    NET_DVR_FILEOPENFAIL                35  //打开文件出错
#define    NET_DVR_OPERNOTFINISH                36  //上次的操作还没有完成
#define    NET_DVR_GETPLAYTIMEFAIL                37  //获取当前播放的时间出错
#define    NET_DVR_PLAYFAIL                    38  //播放出错
#define NET_DVR_FILEFORMAT_ERROR            39  //文件格式不正确
#define NET_DVR_DIR_ERROR                    40    //路径错误
#define NET_DVR_ALLOC_RESOURCE_ERROR        41  //资源分配错误
#define NET_DVR_AUDIO_MODE_ERROR            42    //声卡模式错误
#define NET_DVR_NOENOUGH_BUF                43    //缓冲区太小
#define NET_DVR_CREATESOCKET_ERROR            44    //创建SOCKET出错
#define NET_DVR_SETSOCKET_ERROR                45    //设置SOCKET出错
#define NET_DVR_MAX_NUM                        46    //个数达到最大
#define NET_DVR_USERNOTEXIST                47    //用户不存在
#define NET_DVR_WRITEFLASHERROR                48  //写FLASH出错
#define NET_DVR_UPGRADEFAIL                    49  //DVR升级失败
#define NET_DVR_CARDHAVEINIT                50  //解码卡已经初始化过
#define NET_DVR_PLAYERFAILED                51    //调用播放库中某个函数失败
#define NET_DVR_MAX_USERNUM                    52  //设备端用户数达到最大
#define NET_DVR_GETLOCALIPANDMACFAIL        53  //获得客户端的IP地址或物理地址失败
#define NET_DVR_NOENCODEING                    54    //该通道没有编码
#define NET_DVR_IPMISMATCH                    55    //IP地址不匹配
#define NET_DVR_MACMISMATCH                    56    //MAC地址不匹配
#define NET_DVR_UPGRADELANGMISMATCH            57    //升级文件语言不匹配
#define NET_DVR_MAX_PLAYERPORT                58    //播放器路数达到最大
#define NET_DVR_NOSPACEBACKUP                59    //备份设备中没有足够空间进行备份
#define NET_DVR_NODEVICEBACKUP                60    //没有找到指定的备份设备
#define NET_DVR_PICTURE_BITS_ERROR            61    //图像素位数不符，限24色
#define NET_DVR_PICTURE_DIMENSION_ERROR        62    //图片高*宽超限， 限128*256
#define NET_DVR_PICTURE_SIZ_ERROR            63    //图片大小超限，限100K
#define NET_DVR_LOADPLAYERSDKFAILED            64    //载入当前目录下Player Sdk出错
#define NET_DVR_LOADPLAYERSDKPROC_ERROR        65    //找不到Player Sdk中某个函数入口
#define NET_DVR_LOADDSSDKFAILED                66    //载入当前目录下DSsdk出错
#define NET_DVR_LOADDSSDKPROC_ERROR            67    //找不到DsSdk中某个函数入口
#define NET_DVR_DSSDK_ERROR                    68    //调用硬解码库DsSdk中某个函数失败
#define NET_DVR_VOICEMONOPOLIZE                69    //声卡被独占
#define NET_DVR_JOINMULTICASTFAILED            70    //加入多播组失败
#define NET_DVR_CREATEDIR_ERROR                71    //建立日志文件目录失败
#define NET_DVR_BINDSOCKET_ERROR            72    //绑定套接字失败
#define NET_DVR_SOCKETCLOSE_ERROR            73    //socket连接中断，此错误通常是由于连接中断或目的地不可达
#define NET_DVR_USERID_ISUSING                74    //注销时用户ID正在进行某操作
#define NET_DVR_SOCKETLISTEN_ERROR            75    //监听失败
#define NET_DVR_PROGRAM_EXCEPTION            76    //程序异常
#define NET_DVR_WRITEFILE_FAILED            77    //写文件失败
#define NET_DVR_FORMAT_READONLY                78  //禁止格式化只读硬盘
#define NET_DVR_WITHSAMEUSERNAME            79  //用户配置结构中存在相同的用户名
#define NET_DVR_DEVICETYPE_ERROR            80  /*导入参数时设备型号不匹配*/
#define NET_DVR_LANGUAGE_ERROR              81  /*导入参数时语言不匹配*/
#define NET_DVR_PARAVERSION_ERROR           82  /*导入参数时软件版本不匹配*/
#define NET_DVR_IPCHAN_NOTALIVE             83  /*预览时外接IP通道不在线*/
#define NET_DVR_RTSP_SDK_ERROR                84    /*加载高清IPC通讯库StreamTransClient.dll失败*/
#define NET_DVR_CONVERT_SDK_ERROR            85    /*加载转码库失败*/
#define NET_DVR_IPC_COUNT_OVERFLOW            86  /*超出最大的ip接入通道数*/

/**********************云台控制命令 begin*************************/
#define LIGHT_PWRON        2    /* 接通灯光电源 */
#define WIPER_PWRON        3    /* 接通雨刷开关 */
#define FAN_PWRON        4    /* 接通风扇开关 */
#define HEATER_PWRON    5    /* 接通加热器开关 */
#define AUX_PWRON1        6    /* 接通辅助设备开关 */
#define AUX_PWRON2        7    /* 接通辅助设备开关 */
#define SET_PRESET        8    /* 设置预置点 */
#define CLE_PRESET        9    /* 清除预置点 */

#define ZOOM_IN            11    /* 焦距以速度SS变大(倍率变大) */
#define ZOOM_OUT        12    /* 焦距以速度SS变小(倍率变小) */
#define FOCUS_NEAR      13  /* 焦点以速度SS前调 */
#define FOCUS_FAR       14  /* 焦点以速度SS后调 */
#define IRIS_OPEN       15  /* 光圈以速度SS扩大 */
#define IRIS_CLOSE      16  /* 光圈以速度SS缩小 */

#define TILT_UP            21    /* 云台以SS的速度上仰 */
#define TILT_DOWN        22    /* 云台以SS的速度下俯 */
#define PAN_LEFT        23    /* 云台以SS的速度左转 */
#define PAN_RIGHT        24    /* 云台以SS的速度右转 */
#define UP_LEFT            25    /* 云台以SS的速度上仰和左转 */
#define UP_RIGHT        26    /* 云台以SS的速度上仰和右转 */
#define DOWN_LEFT        27    /* 云台以SS的速度下俯和左转 */
#define DOWN_RIGHT        28    /* 云台以SS的速度下俯和右转 */
#define PAN_AUTO        29    /* 云台以SS的速度左右自动扫描 */

#define FILL_PRE_SEQ    30    /* 将预置点加入巡航序列 */
#define SET_SEQ_DWELL    31    /* 设置巡航点停顿时间 */
#define SET_SEQ_SPEED    32    /* 设置巡航速度 */
#define CLE_PRE_SEQ        33    /* 将预置点从巡航序列中删除 */
#define STA_MEM_CRUISE    34    /* 开始记录轨迹 */
#define STO_MEM_CRUISE    35    /* 停止记录轨迹 */
#define RUN_CRUISE        36    /* 开始轨迹 */
#define RUN_SEQ            37    /* 开始巡航 */
#define STOP_SEQ        38    /* 停止巡航 */
#define GOTO_PRESET        39    /* 快球转到预置点 */
/**********************云台控制命令 end*************************/

/**********************回放控制命令 begin*************************/
#define NET_DVR_PLAYSTART        1//开始播放
#define NET_DVR_PLAYPAUSE        3//暂停播放
#define NET_DVR_PLAYRESTART        4//恢复播放
#define NET_DVR_PLAYGETPOS        13//获取文件回放的进度
#define NET_DVR_GETTOTALFRAMES  16//获取当前播放文件总的帧数(按文件回放的时候有效)
#define NET_DVR_GETTOTALTIME    17//获取当前播放文件总的时间(按文件回放的时候有效)
#define NET_DVR_SETSPEED        24//设置码流速度
#define NET_DVR_PLAYGETTOTALLEN    27//获取按时间回放对应时间段内的所有文件的总长度
/**********************回放控制命令 end*************************/

/**********************操作异常类型 begin************************/
#define EXCEPTION_EXCHANGE            0x8000    //用户交互时异常
#define EXCEPTION_AUDIOEXCHANGE        0x8001    //语音对讲异常
#define EXCEPTION_ALARM                0x8002    //报警异常
#define EXCEPTION_PREVIEW            0x8003    //网络预览异常
#define EXCEPTION_RECONNECT            0x8005    //预览时重连
#define EXCEPTION_ALARMRECONNECT    0x8006    //报警时重连
#define EXCEPTION_PLAYBACK            0x8010    //回放异常
/**********************操作异常类型 end************************/

/*********************报警回调类型 begin************************/
#define COMM_ALARM                    0x1100    //8000报警信息主动上传
#define COMM_ALARM_V30                0x4000    //9000报警信息主动上传
/*********************报警回调类型 end************************/

/**********************预览回调函数 begin*********************/
#define NET_DVR_SYSHEAD                1        //系统头数据
#define NET_DVR_STREAMDATA            2        //视频流数据（包括复合流和音视频分开的视频流数据）
#define NET_DVR_AUDIOSTREAMDATA        3        //音频流数据
#define NET_DVR_STD_VIDEODATA    4    //标准视频流数据
#define NET_DVR_STD_AUDIODATA    5    //标准音频流数据
/**********************预览回调函数 end*********************/

/************************查找文件返回值 begin*************************/
#define NET_DVR_FILE_SUCCESS        1000    //获得文件信息
#define NET_DVR_FILE_NOFIND            1001    //没有文件
#define NET_DVR_ISFINDING            1002    //正在查找文件
#define    NET_DVR_NOMOREFILE            1003    //查找文件时没有更多的文件
#define    NET_DVR_FILE_EXCEPTION        1004    //查找文件时异常
/************************查找文件返回值 end*************************/

#define   STEP_READY       0    //准备升级
#define   STEP_RECV_DATA   1    //接收升级包数据
#define   STEP_UPGRADE     2    //升级系统
#define   STEP_BACKUP      3    //备份系统
#define   STEP_SEARCH      255  //搜索升级文件

/* 设备类型 */
#define DVR                            1                /*对尚未定义的dvr类型返回NETRET_DVR*/
#define ATMDVR                        2                /*atm dvr*/
#define DVS                            3                /*DVS*/
#define DEC                            4                /* 6001D */
#define ENC_DEC                        5                /* 6001F */
#define DVR_HC                        6                /*8000HC*/
#define DVR_HT                        7                /*8000HT*/
#define DVR_HF                        8                /*8000HF*/
#define DVR_HS                        9                /* 8000HS DVR(no audio) */
#define DVR_HTS                        10              /* 8016HTS DVR(no audio) */
#define DVR_HB                        11              /* HB DVR(SATA HD) */
#define DVR_HCS                        12              /* 8000HCS DVR */
#define DVS_A                        13              /* 带ATA硬盘的DVS */
#define DVR_HC_S                    14              /* 8000HC-S */
#define DVR_HT_S                    15              /* 8000HT-S */
#define DVR_HF_S                    16              /* 8000HF-S */
#define DVR_HS_S                    17              /* 8000HS-S */
#define ATMDVR_S                    18              /* ATM-S */
#define DVR_7000H                    19                /*7000H系列*/
#define DEC_MAT                        20              /*多路解码器*/
#define DVR_MOBILE                    21                /* mobile DVR */
#define DVR_HD_S                    22              /* 8000HD-S */
#define DVR_HD_SL                    23                /* 8000HD-SL */
#define DVR_HC_SL                    24                /* 8000HC-SL */
#define DVR_HS_ST                    25                /* 8000HS_ST */
#define DVS_HW                        26              /* 6000HW */
#define DS630X_D                    27              /* 多路解码器 */
#define DS640X_HD                    28                /*640X高清解码器*/
#define DS610X_D                    29              /*610X解码器*/
#define IPCAM                        30                /*IP 摄像机*/
#define MEGA_IPCAM                    31                /*852F&852MF*/
#define IPCAM_X62MF                    32                /*862MF可以接入9000设备*/
#define ITCCAM                      35              /*智能高清网络摄像机*/
#define ZOOMCAM                     38              /*一体机*/
#define IPDOME                      40              /*IP 标清球机*/
#define IPDOME_MEGA200              41              /*IP 200万高清球机*/
#define IPDOME_MEGA130              42              /*IP 130万高清球机*/
#define IPDOME_AI                   43              /*IP 高清智能快球*/
#define TII_IPCAM                   44              /*红外热成像摄像机*/
#define IPMOD                        50                /*IP 模块*/
#define IDS6501_HF_P                60              // 6501 车牌
#define IDS6101_HF_A                61              //智能ATM
#define IDS6002_HF_B                62                //双机跟踪：DS6002-HF/B
#define IDS6101_HF_B                63              //行为分析：DS6101-HF/B DS6101-HF/B_SATA
#define IDS52XX                        64                //智能分析仪IVMS
#define IDS90XX                        65                // 9000智能
#define IDS8104_AHL_S_HX            66                // 海鑫人脸识别 ATM
#define IDS8104_AHL_S_H             67              // 私有人脸识别 ATM
#define IDS91XX                        68                // 9100智能
#define IIP_CAM_B                   69              // 智能行为IP摄像机
#define DS71XX_H                    71                /* DS71XXH_S */
#define DS72XX_H_S                    72                /* DS72XXH_S */
#define DS73XX_H_S                    73                /* DS73XXH_S */
#define DS72XX_HF_S                 74              //DS72XX_HF_S
#define DS73XX_HFI_S                75              //DS73XX_HFI_S
#define DS76XX_H_S                    76                /* DVR,e.g. DS7604_HI_S */
#define DS76XX_N_S                    77                /* NVR,e.g. DS7604_NI_S */
#define DS81XX_HS_S                    81                /* DS81XX_HS_S */
#define DS81XX_HL_S                    82                /* DS81XX_HL_S */
#define DS81XX_HC_S                    83                /* DS81XX_HC_S */
#define DS81XX_HD_S                    84                /* DS81XX_HD_S */
#define DS81XX_HE_S                    85                /* DS81XX_HE_S */
#define DS81XX_HF_S                    86                /* DS81XX_HF_S */
#define DS81XX_AH_S                    87                /* DS81XX_AH_S */
#define DS81XX_AHF_S                88                /* DS81XX_AHF_S */
#define DS90XX_HF_S                    90              /*DS90XX_HF_S*/
#define DS91XX_HF_S                    91              /*DS91XX_HF_S*/
#define DS91XX_HD_S                    92              /*91XXHD-S(MD)*/
#define IDS90XX_A                    93                // 9000智能 ATM
#define IDS91XX_A                    94                // 9100智能 ATM
#define DS95XX_N_S                    95              /*DS95XX_N_S NVR 不带任何输出*/
#define DS96XX_N_SH                    96              /*DS96XX_N_SH NVR*/
#define DS90XX_HF_SH                97              /*DS90XX_HF_SH */
#define DS91XX_HF_SH                98              /*DS91XX_HF_SH */
#define DS_B10_XY                   100             /*视频综合平台设备型号(X:编码板片数，Y:解码板片数)*/
#define DS_6504HF_B10               101             /*视频综合平台内部编码器*/
#define DS_6504D_B10                102             /*视频综合平台内部解码器*/
#define DS_1832_B10                 103             /*视频综合平台内部码分器*/
#define DS_6401HFH_B10              104             /*视频综合平台内部光纤板*/
#define DS_65XXHC                    105                //65XXHC DVS
#define DS_65XXHC_S                    106                //65XXHC-SATA DVS
#define DS_65XXHF                    107                //65XXHF DVS
#define DS_65XXHF_S                    108                //65XXHF-SATA DVS
#define DS_6500HF_B                 109             //65 rack DVS
#define IVMS_6200_C                 110             //iVMS-6200(/C)
#define IVMS_6200_B                 111             //iVMS-6200(/B)
#define DS_72XXHV_ST15                112                //72XXHV_ST15 DVR
#define DS_72XXHV_ST20                113                //72XXHV_ST20 DVR
#define IVMS_6200_T                    114             //IVMS-6200(/T)
#define IVMS_6200_BP                115             //IVMS-6200(/BP)
#define DS_81XXHC_ST                116                //DS_81XXHC_ST
#define DS_81XXHS_ST                117                //DS_81XXHS_ST
#define DS_81XXAH_ST                118                //DS_81XXAH_ST
#define DS_81XXAHF_ST                119                //DS_81XXAHF_ST
#define DS_66XXDVS                    120                //66XX DVS
#define DS_1964_B10                 121             /*视频综合平台内部报警器*/
#define DS_B10N04_IN                122             /*视频综合平台内部级联输入*/
#define DS_B10N04_OUT                123             /*视频综合平台内部级联输出*/
#define DS_B10N04_INTEL             124             /*视频综合平台内部智能*/
#define DS_6408HFH_B10E_RM          125             //V6高清
#define DS_B10N64F1_RTM             126             //V6级联不带DSP
#define DS_B10N64F1D_RTM            127             //V6级联带DSP
#define DS_B10_SDS                  128             //视频综合平台子域控制器
#define DS_B10_DS                   129             //视频综合平台域控制器
#define DS_6401HFH_B10V                130            //VGA高清编码器
#define DS_6504D_B10B               131             /*视频综合平台内部标清解码器*/
#define DS_6504D_B10H               132             /*视频综合平台内部高清解码器*/
#define DS_6504D_B10V               133             /*视频综合平台内部VGA解码器*/
#define DS_6408HFH_B10S                134             //视频综合平台SDI子板
#define DS_18XX_N                    135             /*矩阵接入网关*/

#define DS_19DXX                    145                /*动环监控报警主机*/
#define DS_19XX                     146             /*1900系列报警主机*/

#define IDS_8104_AHFL_S_H           171             // 8104ATM
#define IDS_65XX_HF_A               172             // 65 ATM
#define IDS90XX_HF_RH               173             // 9000 智能RH
#define IDS91XX_HF_RH               174             // 9100 智能RH设备
#define IDS_65XX_HF_B               175             // 65 行为分析
#define IDS_65XX_HF_P               176             // 65 车牌识别
#define IVMS_6200_F                177             // IVMS-6200(/F)
#define IVMS_6200_A                 178             //iVMS-6200(/A)

#define DS90XX_HF_RH                181             // 9000 RH    648
#define DS91XX_HF_RH                182             // 9100 RH设备 648
#define DS78XX_S                    183             // 78系列设备 6446
#define DS81XXHW_S                    185                // 81 Resolution 960 KY2011
#define DS81XXHW_ST                    186             // DS81XXHW_ST  KY2011
#define DS91XXHW_ST                    187             // DS91XXHW_ST  KY2011
#define DS91XX_ST                    188             // DS91XX_ST netra
#define DS81XX_ST                    189             // DS81XX_ST netra
#define DS81XXHX_ST                    190             // DS81XXHDI_ST,DS81XXHE_ST ky2012
#define DS73XXHX_ST                    191             // DS73XXHI_ST ky2012
#define DS81XX_SH                   192             // 审讯81SH,81SHF
#define DS81XX_SN                   193             // 审讯81SNL

#define DS96XXN_ST                  194             //NVR:DS96xxN_ST
#define DS86XXN_ST                  195             //NVR:DS86xxN_ST
#define DS80XXHF_ST                 196             //DVR:DS80xxHF_ST
#define DS90XXHF_ST                 197             //DVR:DS90xxHF_ST
#define DS76XXN_ST                  198             //NVR:DS76xxN_ST

#define ENCODER_SERVER                200                // 编码卡服务器
#define DECODER_SERVER              201                // 解码卡服务器
#define PCNVR_SERVER                202                // PCNVR存储服务器

/******************************能力集获取*********************************/
//能力获取命令
#define DEVICE_SOFTHARDWARE_ABILITY         0x001  //设备软硬件能力
#define DEVICE_NETWORK_ABILITY              0x002  //设备网络能力
#define DEVICE_ENCODE_ALL_ABILITY           0x003  //设备所有编码能力
#define    DEVICE_ENCODE_CURRENT               0x004  //设备当前编码能力
#define IPC_FRONT_PARAMETER                    0x005     //ipc前端参数1.0
#define IPC_UPGRADE_DESCRIPTION                0x006     //ipc升级信息
#define DEVICE_RAID_ABILITY                 0x007  //RAID能力
#define DEVICE_ENCODE_ALL_ABILITY_V20       0x008     //设备所有编码能力2.0
#define IPC_FRONT_PARAMETER_V20                0x009     //ipc前端参数2.0
#define DEVICE_ALARM_ABILITY                0x00a  //辅助报警能力
#define DEVICE_DYNCHAN_ABILITY                0x00b  //设备数字通道能力
#define DEVICE_USER_ABILITY                 0x00c  //设备用户管理参数能力
#define DEVICE_NETAPP_ABILITY               0x00d  //设备网络应用参数能力
#define DEVICE_VIDEOPIC_ABILITY             0x00e  //设备图像参数能力
#define DEVICE_JPEG_CAP_ABILITY             0x00f  //设备JPEG抓图能力
#define DEVICE_SERIAL_ABILITY               0x010  //RS232和RS485串口能力
#define DEVICE_ABILITY_INFO                    0x011     //设备通用能力类型，具体能力根据发送的能力节点来区分
#define STREAM_ABILITY                      0x012  //流能力
#define SYSTEM_MANAGEMENT_ABILITY           0x013  //设备系统管理能力
#define IP_VIEW_DEV_ABILITY                    0x014  //IP可视对讲分机能力
#define VCA_DEV_ABILITY                    0x100  //设备智能分析的总能力
#define VCA_CHAN_ABILITY                    0x110  //行为分析能力
#define MATRIXDECODER_ABILITY               0x200  //多路解码器显示、解码能力
#define VIDEOPLATFORM_ABILITY               0x210 //视频综合平台能力集
#define VIDEOPLATFORM_SBUCODESYSTEM_ABILITY 0x211 //视频综合平台编码子系统能力集
#define WALL_ABILITY                        0x212  //电视墙能力集
#define MATRIX_ABILITY                      0x213  //SDI矩阵能力
#define DECODECARD_ABILITY                  0x220 //解码卡服务器能力集
#define VIDEOPLATFORM_ABILITY_V40           0x230 //视频综合平台能力集
#define MATRIXMANAGEDEVICE_ABILITY          0x240 //矩阵接入网关能力集
#define MATRIXDECODER_ABILITY_V41           0x260 //解码器能力集
#define DECODER_ABILITY                     0x261 //解码器xml能力集
#define DECODECARD_ABILITY_V41              0x270 //解码卡服务器能力集V41
#define CODECARD_ABILITY                    0x271  //编码卡能力集
#define SNAPCAMERA_ABILITY                  0x300  //抓拍机能力集
#define ITC_TRIGGER_MODE_ABILITY            0x301  //智能IPC设备的触发模式能力
#define COMPRESSIONCFG_ABILITY              0x400  //获取压缩参数能力集合
#define COMPRESSION_LIMIT                   0x401  //获取主子码流压缩参数能力限制
#define PIC_CAPTURE_ABILITY                    0x402  //获图片分辨率能力集合
#define ALARMHOST_ABILITY                   0x500 //网络报警主机能力集
#define IT_DEVICE_ABILITY                   0x501  //智能交通能力集
#define    SCREENCONTROL_ABILITY                0x600    //大屏控制器能力集
#define    SCREENSERVER_ABILITY                0x610    //大屏服务器能力集
#define FISHEYE_ABILITY                     0x700   //鱼眼能力集
#define LCD_SCREEN_ABILITY                    0x800    //LCD屏幕能力 2013-10-12

//sdk网络环境枚举变量，用于远程升级
typedef enum _SDK_NET_ENV {
    LOCAL_AREA_NETWORK = 0,
    WIDE_AREA_NETWORK
} SDK_NETWORK_ENVIRONMENT;

//NET_DVR_Login_V30()参数结构
typedef struct {
    BYTE sSerialNumber[SERIALNO_LEN];  //序列号
    BYTE byAlarmInPortNum;                //报警输入个数
    BYTE byAlarmOutPortNum;                //报警输出个数
    BYTE byDiskNum;                    //硬盘个数
    BYTE byDVRType;                    //设备类型, 1:DVR 2:ATM DVR 3:DVS ......
    BYTE byChanNum;                    //模拟通道个数
    BYTE byStartChan;                    //起始通道号,例如DVS-1,DVR - 1
    BYTE byAudioChanNum;                //语音通道数
    BYTE byIPChanNum;                    //最大数字通道个数，低位
    BYTE byZeroChanNum;            //零通道编码个数 //2010-01-16
    BYTE byMainProto;            //主码流传输协议类型 0-private, 1-rtsp,2-同时支持private和rtsp
    BYTE bySubProto;                //子码流传输协议类型0-private, 1-rtsp,2-同时支持private和rtsp
    BYTE bySupport;        //能力，位与结果为0表示不支持，1表示支持，
    //bySupport & 0x1, 表示是否支持智能搜索
    //bySupport & 0x2, 表示是否支持备份
    //bySupport & 0x4, 表示是否支持压缩参数能力获取
    //bySupport & 0x8, 表示是否支持多网卡
    //bySupport & 0x10, 表示支持远程SADP
    //bySupport & 0x20, 表示支持Raid卡功能
    //bySupport & 0x40, 表示支持IPSAN 目录查找
    //bySupport & 0x80, 表示支持rtp over rtsp
    BYTE bySupport1;        // 能力集扩充，位与结果为0表示不支持，1表示支持
    //bySupport1 & 0x1, 表示是否支持snmp v30
    //bySupport1 & 0x2, 支持区分回放和下载
    //bySupport1 & 0x4, 是否支持布防优先级
    //bySupport1 & 0x8, 智能设备是否支持布防时间段扩展
    //bySupport1 & 0x10, 表示是否支持多磁盘数（超过33个）
    //bySupport1 & 0x20, 表示是否支持rtsp over http
    //bySupport1 & 0x80, 表示是否支持车牌新报警信息2012-9-28, 且还表示是否支持NET_DVR_IPPARACFG_V40结构体
    BYTE bySupport2;
    /*能力，位与结果为0表示不支持，非0表示支持
                             bySupport2 & 0x1, 表示解码器是否支持通过URL取流解码
                             bySupport2 & 0x2,  表示支持FTPV40
                             bySupport2 & 0x4,  表示支持ANR
                             bySupport2 & 0x8,  表示支持CCD的通道参数配置
                             bySupport2 & 0x10,  表示支持布防报警回传信息（仅支持抓拍机报警 新老报警结构）
                             bySupport2 & 0x20,  表示是否支持单独获取设备状态子项
                             bySupport2 & 0x40,  表示是否是码流加密设备*/
    WORD wDevType;              //设备型号
    BYTE bySupport3; //能力集扩展，位与结果为0表示不支持，1表示支持
    //bySupport3 & 0x1, 表示是否多码流
    // bySupport3 & 0x4 表示支持按组配置， 具体包含 通道图像参数、报警输入参数、IP报警输入、输出接入参数、
    // 用户参数、设备工作状态、JPEG抓图、定时和时间抓图、硬盘盘组管理
    //bySupport3 & 0x8为1 表示支持使用TCP预览、UDP预览、多播预览中的"延时预览"字段来请求延时预览（后续都将使用这种方式请求延时预览）。而当bySupport3 & 0x8为0时，将使用 "私有延时预览"协议。
    //bySupport3 & 0x10 表示支持"获取报警主机主要状态（V40）"。
    //bySupport3 & 0x20 表示是否支持通过DDNS域名解析取流

    BYTE byMultiStreamProto;
    //是否支持多码流,按位表示,0-不支持,1-支持,bit1-码流3,bit2-码流4,bit7-主码流，bit-8子码流
    BYTE byStartDChan;        //起始数字通道号,0表示无效
    BYTE byStartDTalkChan;    //起始数字对讲通道号，区别于模拟对讲通道号，0表示无效
    BYTE byHighDChanNum;        //数字通道个数，高位
    BYTE bySupport4;
    BYTE byLanguageType;
    // 支持语种能力,按位表示,每一位0-不支持,1-支持
    //  byLanguageType 等于0 表示 老设备
    //  byLanguageType & 0x1表示支持中文
    //  byLanguageType & 0x2表示支持英文
    BYTE byRes2[9];        //保留
} NET_DVR_DEVICEINFO_V30, *LPNET_DVR_DEVICEINFO_V30;

//软解码预览参数
typedef struct {
    LONG lChannel;
    //通道号
    LONG lLinkMode;
    //最高位(31)为0表示主码流，为1表示子，0－30位表示码流连接方式: 0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-RTP/RTSP,5-RSTP/HTTP
    HWND hPlayWnd;
    //播放窗口的句柄,为NULL表示不播放图象
    char *sMultiCastIP;
    //多播组地址
    BYTE byProtoType; //应用层取流协议，0-私有协议，1-RTSP协议
    BYTE byRes[3];
} NET_DVR_CLIENTINFO, *LPNET_DVR_CLIENTINFO;

//巡航点配置(私有IP快球专用)
typedef struct {
    BYTE PresetNum;    //预置点
    BYTE Dwell;        //停留时间
    BYTE Speed;        //速度
    BYTE Reserve;    //保留
} NET_DVR_CRUISE_POINT, *LPNET_DVR_CRUISE_POINT;

typedef struct {
    NET_DVR_CRUISE_POINT struCruisePoint[32];            //最大支持32个巡航点
} NET_DVR_CRUISE_RET, *LPNET_DVR_CRUISE_RET;

//校时结构参数
typedef struct {
    DWORD dwYear;        //年
    DWORD dwMonth;        //月
    DWORD dwDay;        //日
    DWORD dwHour;        //时
    DWORD dwMinute;        //分
    DWORD dwSecond;        //秒
} NET_DVR_TIME, *LPNET_DVR_TIME;

//时间段(子结构)
typedef struct {
    //开始时间
    BYTE byStartHour;
    BYTE byStartMin;
    //结束时间
    BYTE byStopHour;
    BYTE byStopMin;
} NET_DVR_SCHEDTIME, *LPNET_DVR_SCHEDTIME;


//报警和异常处理结构(子结构)(多处使用)(9000扩展)
typedef struct {
    DWORD dwHandleType;    /*处理方式,处理方式的"或"结果*/
    /*0x00: 无响应*/
    /*0x01: 监视器上警告*/
    /*0x02: 声音警告*/
    /*0x04: 上传中心*/
    /*0x08: 触发报警输出*/
    /*0x10: 触发JPRG抓图并上传Email*/
    /*0x20: 无线声光报警器联动*/
    /*0x40: 联动电子地图(目前只有PCNVR支持)*/
    /*0x200: 抓图并上传FTP*/
    BYTE byRelAlarmOut[MAX_ALARMOUT_V30];
    //报警触发的输出通道,报警触发的输出,为1表示触发该输出
} NET_DVR_HANDLEEXCEPTION_V30, *LPNET_DVR_HANDLEEXCEPTION_V30;

//DVR设备参数
typedef struct {
    DWORD dwSize;
    BYTE sDVRName[NAME_LEN];     //DVR名称
    DWORD dwDVRID;                //DVR ID,用于遥控器 //V1.4(0-99), V1.5(0-255)
    DWORD dwRecycleRecord;        //是否循环录像,0:不是; 1:是
    //以下不可更改
    BYTE sSerialNumber[SERIALNO_LEN];  //序列号
    DWORD dwSoftwareVersion;            //软件版本号,高16位是主版本,低16位是次版本
    DWORD dwSoftwareBuildDate;            //软件生成日期,0xYYYYMMDD
    DWORD dwDSPSoftwareVersion;            //DSP软件版本,高16位是主版本,低16位是次版本
    DWORD dwDSPSoftwareBuildDate;        // DSP软件生成日期,0xYYYYMMDD
    DWORD dwPanelVersion;                // 前面板版本,高16位是主版本,低16位是次版本
    DWORD dwHardwareVersion;    // 硬件版本,高16位是主版本,低16位是次版本
    BYTE byAlarmInPortNum;        //DVR报警输入个数
    BYTE byAlarmOutPortNum;        //DVR报警输出个数
    BYTE byRS232Num;            //DVR 232串口个数
    BYTE byRS485Num;            //DVR 485串口个数
    BYTE byNetworkPortNum;        //网络口个数
    BYTE byDiskCtrlNum;            //DVR 硬盘控制器个数
    BYTE byDiskNum;                //DVR 硬盘个数
    BYTE byDVRType;                //DVR类型, 1:DVR 2:ATM DVR 3:DVS ......
    BYTE byChanNum;                //DVR 通道个数
    BYTE byStartChan;            //起始通道号,例如DVS-1,DVR - 1
    BYTE byDecordChans;            //DVR 解码路数
    BYTE byVGANum;                //VGA口的个数
    BYTE byUSBNum;                //USB口的个数
    BYTE byAuxoutNum;            //辅口的个数
    BYTE byAudioNum;            //语音口的个数
    BYTE byIPChanNum;            //最大数字通道数
} NET_DVR_DEVICECFG, *LPNET_DVR_DEVICECFG;

/*
 IP地址
 */
typedef struct {
    char sIpV4[16];
    /* IPv4地址 */
    BYTE byIPv6[128];                        /* 保留 */
} NET_DVR_IPADDR, *LPNET_DVR_IPADDR;

/*
 网络数据结构(子结构)(9000扩展)
 */
typedef struct {
    NET_DVR_IPADDR struDVRIP;                            //DVR IP地址
    NET_DVR_IPADDR struDVRIPMask;  //DVR IP地址掩码
    DWORD dwNetInterface;                                //网络接口1-10MBase-T 2-10MBase-T全双工 3-100MBase-TX 4-100M全双工 5-10M/100M自适应
    WORD wDVRPort;                                        //端口号
    WORD wMTU;                                            //增加MTU设置，默认1500。
    BYTE byMACAddr[MACADDR_LEN];                            // 物理地址
    BYTE byRes[2];              //保留
} NET_DVR_ETHERNET_V30, *LPNET_DVR_ETHERNET_V30;

//pppoe结构
typedef struct {
    DWORD dwPPPOE;                                        //0-不启用,1-启用
    BYTE sPPPoEUser[NAME_LEN];                            //PPPoE用户名
    char sPPPoEPassword[PASSWD_LEN];                        // PPPoE密码
    NET_DVR_IPADDR struPPPoEIP;                            //PPPoE IP地址
} NET_DVR_PPPOECFG, *LPNET_DVR_PPPOECFG;

//网络配置结构(9000扩展)
typedef struct {
    DWORD dwSize;
    NET_DVR_ETHERNET_V30 struEtherNet[MAX_ETHERNET];        //以太网口
    NET_DVR_IPADDR struRes1[2];                            //保留
    NET_DVR_IPADDR struAlarmHostIpAddr;                    //报警主机IP地址
    WORD wRes2[2];                                        //保留
    WORD wAlarmHostIpPort;
    /* 报警主机端口号 */
    BYTE byUseDhcp;
    /* 是否启用DHCP 0xff-无效 0-不启用 1-启用*/
    BYTE byRes3;                                            //保留
    NET_DVR_IPADDR struDnsServer1IpAddr;
    /* 域名服务器1的IP地址 */
    NET_DVR_IPADDR struDnsServer2IpAddr;
    /* 域名服务器2的IP地址 */
    BYTE byIpResolver[MAX_DOMAIN_NAME];
    /* IP解析服务器域名或IP地址 */
    WORD wIpResolverPort;
    /* IP解析服务器端口号 */
    WORD wHttpPortNo;
    /* HTTP端口号 */
    NET_DVR_IPADDR struMulticastIpAddr;
    /* 多播组地址 */
    NET_DVR_IPADDR struGatewayIpAddr;
    /* 网关地址 */
    NET_DVR_PPPOECFG struPPPoE;
    BYTE byRes[64];
} NET_DVR_NETCFG_V30, *LPNET_DVR_NETCFG_V30;

//移动侦测(子结构)(9000扩展)
typedef struct {
    BYTE byMotionScope[64][96];
    /*侦测区域,0-96位,表示64行,共有96*64个小宏块,为1表示是移动侦测区域,0-表示不是*/
    BYTE byMotionSensitive;
    /*移动侦测灵敏度, 0 - 5,越高越灵敏,oxff关闭*/
    BYTE byEnableHandleMotion;
    /* 是否处理移动侦测 0－否 1－是*/
    BYTE byRes;
    /* 保留 */
    char reservedData;
    NET_DVR_HANDLEEXCEPTION_V30 struMotionHandleType;
    /* 处理方式 */
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];
    /*布防时间*/
    BYTE byRelRecordChan[MAX_CHANNUM_V30];                                    /* 报警触发的录象通道*/
} NET_DVR_MOTION_V30, *LPNET_DVR_MOTION_V30;

//遮挡报警(子结构)(9000扩展)  区域大小704*576
typedef struct {
    DWORD dwEnableHideAlarm;
    /* 是否启动遮挡报警 ,0-否,1-低灵敏度 2-中灵敏度 3-高灵敏度*/
    WORD wHideAlarmAreaTopLeftX;
    /* 遮挡区域的x坐标 */
    WORD wHideAlarmAreaTopLeftY;
    /* 遮挡区域的y坐标 */
    WORD wHideAlarmAreaWidth;
    /* 遮挡区域的宽 */
    WORD wHideAlarmAreaHeight;
    /*遮挡区域的高*/
    NET_DVR_HANDLEEXCEPTION_V30 strHideAlarmHandleType;
    /* 处理方式 */
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
} NET_DVR_HIDEALARM_V30, *LPNET_DVR_HIDEALARM_V30;

//信号丢失报警(子结构)(9000扩展)
typedef struct {
    BYTE byEnableHandleVILost;
    /* 是否处理信号丢失报警 */
    NET_DVR_HANDLEEXCEPTION_V30 strVILostHandleType;
    /* 处理方式 */
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
} NET_DVR_VILOST_V30, *LPNET_DVR_VILOST_V30;

//遮挡区域(子结构)
typedef struct {
    WORD wHideAreaTopLeftX;
    /* 遮挡区域的x坐标 */
    WORD wHideAreaTopLeftY;
    /* 遮挡区域的y坐标 */
    WORD wHideAreaWidth;
    /* 遮挡区域的宽 */
    WORD wHideAreaHeight;                /*遮挡区域的高*/
} NET_DVR_SHELTER, *LPNET_DVR_SHELTER;

typedef struct {
    BYTE byBrightness;
    /*亮度,0-255*/
    BYTE byContrast;
    /*对比度,0-255*/
    BYTE bySaturation;
    /*饱和度,0-255*/
    BYTE byHue;                /*色调,0-255*/
} NET_DVR_COLOR, *LPNET_DVR_COLOR;

//通道图象结构(9000扩展)
typedef struct {
    DWORD dwSize;
    BYTE sChanName[NAME_LEN];
    DWORD dwVideoFormat;
    /* 只读 视频制式 1-NTSC 2-PAL*/
    BYTE byReservedData[64];
    /*保留*/
    DWORD dwShowChanName; // 预览的图象上是否显示通道名称,0-不显示,1-显示 区域大小704*576
    WORD wShowNameTopLeftX;
    /* 通道名称显示位置的x坐标 */
    WORD wShowNameTopLeftY;                /* 通道名称显示位置的y坐标 */
    //视频信号丢失报警
    NET_DVR_VILOST_V30 struVILost;
    NET_DVR_VILOST_V30 struRes;        /*保留*/
    //	BYTE byRes1[328];
    //移动侦测
    NET_DVR_MOTION_V30 struMotion;
    //遮挡报警
    NET_DVR_HIDEALARM_V30 struHideAlarm;
    //遮挡  区域大小704*576
    DWORD dwEnableHide;
    /* 是否启动遮挡 ,0-否,1-是*/
    NET_DVR_SHELTER struShelter[MAX_SHELTERNUM];
    //OSD
    DWORD dwShowOsd;
    // 预览的图象上是否显示OSD,0-不显示,1-显示 区域大小704*576
    WORD wOSDTopLeftX;
    /* OSD的x坐标 */
    WORD wOSDTopLeftY;
    /* OSD的y坐标 */
    BYTE byOSDType;                    /* OSD类型(主要是年月日格式) */
    /* 0: XXXX-XX-XX 年月日 */
    /* 1: XX-XX-XXXX 月日年 */
    /* 2: XXXX年XX月XX日 */
    /* 3: XX月XX日XXXX年 */
    /* 4: XX-XX-XXXX 日月年*/
    /* 5: XX日XX月XXXX年 */
    /*6: xx/xx/xxxx(月/日/年) */
    /*7: xxxx/xx/xx(年/月/日) */
    /*8: xx/xx/xxxx(日/月/年)*/
    BYTE byDispWeek;
    /* 是否显示星期 */
    BYTE byOSDAttrib;                /* OSD属性:透明，闪烁 */
    /* 1: 透明,闪烁 */
    /* 2: 透明,不闪烁 */
    /* 3: 闪烁,不透明 */
    /* 4: 不透明,不闪烁 */
    BYTE byHourOSDType;
    /* OSD小时制:0-24小时制,1-12小时制 */
    BYTE byFontSize;
    //字体大小，16*16(中)/8*16(英)，1-32*32(中)/16*32(英)，2-64*64(中)/32*64(英)  3-48*48(中)/24*48(英) 0xff-自适应(adaptive)
    BYTE byRes[63];
} NET_DVR_PICCFG_V30, *LPNET_DVR_PICCFG_V30;


//码流压缩参数(子结构)(9000扩展)
typedef struct {
    BYTE byStreamType;        //码流类型 0-视频流, 1-复合流, 表示事件压缩参数时最高位表示是否启用压缩参数
    /*分辨率0-DCIF                      1-CIF,                     2-QCIF,                 3-4CIF,
     4-2CIF                      5（保留）,                 6-QVGA(320*240),        7-QQVGA(160*120),
     12-384*288                  13-576*576,
     16-VGA（640*480）,          17-UXGA（1600*1200）,      18-SVGA(800*600),       19-HD720p(1280*720）,
     20-XVGA,                    21-HD900p,                 23-1536*1536,
     24-1920*1920,               27-HD1080i,
     28-2560*1920,               29-1600*304,               30-2048*1536,           31-2448*2048,
     32-2448*1200,               33-2448*800,               34-XGA（1024*768），    35-SXGA（1280*1024）,
     36-WD1(960*576/960*480),    37-1080i,                  38-WSXGA(1440*900),     39-HD_F(1920*1080/1280*720),
     40-HD_H(1920*540/1280*360), 41-HD_Q(960*540/630*360),  42-2336*1744,           43-1920*1456,
     44-2592*2048,               45-3296*2472,              46-1376*768,            47-1366*768,
     48-1360*768,                49-WSXGA+,                 50-720*720,             51-1280*1280,
     52-2048*768,                53-2048*2048,              54-2560*2048,           55-3072*2048,
     56-2304*1296                57-WXGA(1280*800),         58-1600*600
     0xff-Auto(使用当前码流分辨率)
     */
    BYTE byResolution;
    BYTE byBitrateType;        //码率类型 0:变码率, 1:定码率,0xfe:自动，和源一致
    BYTE byPicQuality;        //图象质量 0-最好 1-次好 2-较好 3-一般 4-较差 5-差,自动，和源一致
    /*视频码率:0-保留，1-16K(保留)，2-32K，3-48k，4-64K，5-80K，6-96K，7-128K，8-160k，9-192K，10-224K，
     11-256K，12-320K，13-384K，14-448K，15-512K，16-640K，17-768K，18-896K，19-1024K，20-1280K，21-1536K，22-1792K，23-2048K，
     24-3072K，25-4096K，26-8192K，27-16384K。最高位(31位)置成1表示是自定义码流，0～30位表示码流值，最小值16k,0xfffffffe，自动，和源一致*/
    DWORD dwVideoBitrate;
    DWORD dwVideoFrameRate;    //帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20; V2.0版本中新加14-15; 15-18; 16-22;
    //17-25；18-30；19-35；20-40；21-45；22-50；23-55；24-60,0xfffffffe-自动，和源一致
    WORD wIntervalFrameI;  //I帧间隔,0xfffe 自动，和源一致
    BYTE byIntervalBPFrame;
    //0-BBP帧; 1-BP帧; 2-单P帧(2006-08-11 增加单P帧的配置接口，可以改善实时流延时问题)；0xfe-自动，和源一致
    BYTE byres1;        //保留
    BYTE byVideoEncType;   //视频编码类型 0-私有264，1-标准h264，2-标准mpeg4，7-M-JPEG，8-MPEG2，0xfe-自动（和源一致），0xff-无效
    BYTE byAudioEncType;   //音频编码类型 0-OggVorbis;1-G711_U;2-G711_A;5-MP2L2;6-G276;7-AAC;0xff-无效
    BYTE byVideoEncComplexity; //视频编码复杂度，0-低，1-中，2高,0xfe:自动，和源一致
    BYTE byEnableSvc; //0 - 不启用SVC功能；1- 启用SVC功能
    BYTE byFormatType; //封装类型，1-裸流，2-RTP封装，3-PS封装，4-TS封装，5-私有，6-FLV，7-ASF，8-3GP,9-RTP+PS（国标：GB28181），0xff-无效
    BYTE byAudioBitRate; //音频码率0-默认，1-8Kbps, 2- 16Kbps, 3-32Kbps，4-64Kbps，5-128Kbps，6-192Kbps；(IPC5.1.0默认4-64Kbps)
    BYTE byres[6];
} NET_DVR_COMPRESSION_INFO_V30, *LPNET_DVR_COMPRESSION_INFO_V30;

//通道压缩参数(9000扩展)
typedef struct {
    DWORD dwSize;
    NET_DVR_COMPRESSION_INFO_V30 struNormHighRecordPara;    //录像 对应8000的普通
    NET_DVR_COMPRESSION_INFO_V30 struRes;
    //保留 char reserveData[28];
    NET_DVR_COMPRESSION_INFO_V30 struEventRecordPara;       //事件触发压缩参数
    NET_DVR_COMPRESSION_INFO_V30 struNetPara;               //网传(子码流)
} NET_DVR_COMPRESSIONCFG_V30, *LPNET_DVR_COMPRESSIONCFG_V30;

//ipc接入设备信息扩展，支持ip设备的域名添加
typedef struct tagNET_DVR_IPDEVINFO_V31 {
    BYTE byEnable;                    //该IP设备是否有效
    BYTE byProType;                    //协议类型，0-私有协议，1-松下协议，2-索尼
    BYTE byEnableQuickAdd;        // 0 不支持快速添加  1 使用快速添加
    // 快速添加需要设备IP和协议类型，其他信息由设备默认指定
    BYTE byRes1;                    //保留字段，置0
    BYTE sUserName[NAME_LEN];        //用户名
    BYTE sPassword[PASSWD_LEN];        //密码
    BYTE byDomain[MAX_DOMAIN_NAME];    //设备域名
    NET_DVR_IPADDR struIP;            //IP地址
    WORD wDVRPort;                    // 端口号
    BYTE byRes2[34];                //保留字段，置0
} NET_DVR_IPDEVINFO_V31, *LPNET_DVR_IPDEVINFO_V31;

/* IP通道匹配参数 */
typedef struct {
    BYTE byEnable;
    /* 该通道是否在线 */
    BYTE byIPID;                    //IP设备ID低8位，当设备ID为0时表示通道不可用
    BYTE byChannel;
    /* 通道号 */
    BYTE byIPIDHigh;                // IP设备ID的高8位
    BYTE byTransProtocol;                //传输协议类型0-TCP/auto(具体有设备决定)，1-UDP 2-多播 3-仅TCP 4-auto
    BYTE byres[31];                    /* 保留 */
} NET_DVR_IPCHANINFO, *LPNET_DVR_IPCHANINFO;

/* 扩展IP接入配置结构 */
typedef struct tagNET_DVR_IPPARACFG_V31 {
    DWORD dwSize;
    /* 结构大小 */
    NET_DVR_IPDEVINFO_V31 struIPDevInfo[MAX_IP_DEVICE];
    /* IP设备 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];
    /* 模拟通道是否启用，从低到高表示1-32通道，0表示无效 1有效 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];    /* IP通道 */
} NET_DVR_IPPARACFG_V31, *LPNET_DVR_IPPARACFG_V31;

//录象文件参数(9000)
typedef struct {
    char sFileName[100];
    //文件名
    NET_DVR_TIME struStartTime;
    //文件的开始时间
    NET_DVR_TIME struStopTime;
    //文件的结束时间
    DWORD dwFileSize;
    //文件的大小
    char sCardNum[32];
    BYTE byLocked;
    //9000设备支持,1表示此文件已经被锁定,0表示正常的文件
    BYTE byFileType;  //文件类型:0－定时录像,1-移动侦测 ，2－报警触发，
    //3-报警|移动侦测 4-报警&移动侦测 5-命令触发 6-手动录像
    BYTE byRes[2];
} NET_DVR_FINDDATA_V30, *LPNET_DVR_FINDDATA_V30;

//录象文件查找条件结构
typedef struct {
    LONG lChannel;
    //通道号
    DWORD dwFileType;
    //录象文件类型0xff－全部，0－定时录像,1-移动侦测 ，2－报警触发，
    //3-报警|移动侦测 4-报警&移动侦测 5-命令触发 6-手动录像
    DWORD dwIsLocked;
    //是否锁定 0-正常文件,1-锁定文件, 0xff表示所有文件
    DWORD dwUseCardNo;
    //是否使用卡号
    BYTE sCardNumber[32];
    //卡号
    NET_DVR_TIME struStartTime;
    //开始时间
    NET_DVR_TIME struStopTime;//结束时间
} NET_DVR_FILECOND, *LPNET_DVR_FILECOND;

//报警设备信息
typedef struct {
    BYTE byUserIDValid;
    /* userid是否有效 0-无效，1-有效 */
    BYTE bySerialValid;
    /* 序列号是否有效 0-无效，1-有效 */
    BYTE byVersionValid;
    /* 版本号是否有效 0-无效，1-有效 */
    BYTE byDeviceNameValid;
    /* 设备名字是否有效 0-无效，1-有效 */
    BYTE byMacAddrValid;
    /* MAC地址是否有效 0-无效，1-有效 */
    BYTE byLinkPortValid;
    /* login端口是否有效 0-无效，1-有效 */
    BYTE byDeviceIPValid;
    /* 设备IP是否有效 0-无效，1-有效 */
    BYTE bySocketIPValid;
    /* socket ip是否有效 0-无效，1-有效 */
    LONG lUserID;
    /* NET_DVR_Login()返回值, 布防时有效 */
    BYTE sSerialNumber[SERIALNO_LEN];
    /* 序列号 */
    DWORD dwDeviceVersion;
    /* 版本信息 高16位表示主版本，低16位表示次版本*/
    char sDeviceName[NAME_LEN];
    /* 设备名字 */
    BYTE byMacAddr[MACADDR_LEN];
    /* MAC地址 */
    WORD wLinkPort;
    /* link port */
    char sDeviceIP[128];
    /* IP地址 */
    char sSocketIP[128];
    /* 报警主动上传时的socket IP地址 */
    BYTE byIpProtocol;
    /* Ip协议 0-IPV4, 1-IPV6 */
    BYTE byRes2[11];
} NET_DVR_ALARMER, *LPNET_DVR_ALARMER;

//报警输出状态(9000扩展)
typedef struct {
    BYTE Output[MAX_ALARMOUT_V30];
} NET_DVR_ALARMOUTSTATUS_V30, *LPNET_DVR_ALARMOUTSTATUS_V30;

//上传报警信息(9000扩展)
typedef struct {
    DWORD dwAlarmType;
    /*0-信号量报警,1-硬盘满,2-信号丢失,3－移动侦测,4－硬盘未格式化,5-读写硬盘出错,6-遮挡报警,7-制式不匹配, 8-非法访问, 9-视频信号异常，
                               10-录像异常 11- 智能场景变化  12-阵列异常 */
    DWORD dwAlarmInputNumber;
    /*报警输入端口*/
    BYTE byAlarmOutputNumber[MAX_ALARMOUT_V30];
    /*触发的输出端口，为1表示对应输出*/
    BYTE byAlarmRelateChannel[MAX_CHANNUM_V30];
    /*触发的录像通道，为1表示对应录像, dwAlarmRelateChannel[0]对应第1个通道*/
    BYTE byChannel[MAX_CHANNUM_V30];
    /*dwAlarmType为2或3,6，9，10时，表示哪个通道，dwChannel[0]对应第1个通道*/
    BYTE byDiskNumber[MAX_DISKNUM_V30];/*dwAlarmType为1,4,5时,表示哪个硬盘, dwDiskNumber[0]对应第1个硬盘*/
} NET_DVR_ALARMINFO_V30, *LPNET_DVR_ALARMINFO_V30;

typedef struct {
    DWORD dwAlarmType;
    /*0-信号量报警,1-硬盘满,2-信号丢失,3－移动侦测,4－硬盘未格式化,5-读写硬盘出错,6-遮挡报警,7-制式不匹配, 8-非法访问, 9-视频信号异常，10-录像异常 11- 智能场景变化*/
    DWORD dwAlarmInputNumber;
    /*报警输入端口*/
    DWORD dwAlarmOutputNumber[MAX_ALARMOUT];
    /*触发的输出端口，哪一位为1表示对应哪一个输出*/
    DWORD dwAlarmRelateChannel[MAX_CHANNUM];
    /*触发的录像通道，哪一位为1表示对应哪一路录像, dwAlarmRelateChannel[0]对应第1个通道*/
    DWORD dwChannel[MAX_CHANNUM];
    /*dwAlarmType为2或3,6,9,10时，表示哪个通道，dwChannel[0]位对应第1个通道*/
    DWORD dwDiskNumber[MAX_DISKNUM];/*dwAlarmType为1,4,5时,表示哪个硬盘, dwDiskNumber[0]位对应第1个硬盘*/
} NET_DVR_ALARMINFO, *LPNET_DVR_ALARMINFO;

//云台区域选择放大缩小(私有 快球专用)
typedef struct {
    int xTop;     //方框起始点的x坐标
    int yTop;     //方框结束点的y坐标
    int xBottom;  //方框结束点的x坐标
    int yBottom;  //方框结束点的y坐标
    int bCounter; //保留
} NET_DVR_POINT_FRAME, *LPNET_DVR_POINT_FRAME;

//图片质量
typedef struct {
    /*	注意：当图像压缩分辨率为VGA时，支持0=CIF, 1=QCIF, 2=D1抓图，
     当分辨率为3=UXGA(1600x1200), 4=SVGA(800x600), 5=HD720p(1280x720),6=VGA,7=XVGA, 8=HD900p
     仅支持当前分辨率的抓图
     */
    WORD wPicSize;
    /* 0-CIF，1-QCIF，2-D1，3-UXGA(1600x1200)，
                             4-SVGA(800x600)，5-HD720p(1280x720)，6-VGA，7-XVGA，8-HD900p，
                             9-HD1080，10-2560*1920，11-1600*304，12-2048*1536，
                             13-2448*2048,14-2448*1200，15-2448*800，
                             16-XGA(1024*768)，17-SXGA(1280*1024),18-WD1(960*576/960*480),19-1080i*/
    WORD wPicQuality;            /* 图片质量系数 0-最好 1-较好 2-一般 */
} NET_DVR_JPEGPARA, *LPNET_DVR_JPEGPARA;

typedef struct {
    BYTE byAudioEncType;
    BYTE byres[7];
} NET_DVR_COMPRESSION_AUDIO, *LPNET_DVR_COMPRESSION_AUDIO;

typedef struct {
    BYTE byIPID;
    BYTE byAlarmOut;
    BYTE byRes[18];
} NET_DVR_IPALARMOUTINFO, *LPNET_DVR_IPALARMOUTINFO;

typedef struct {
    DWORD dwSize;
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT];
} NET_DVR_IPALARMOUTCFG, *LPNET_DVR_IPALARMOUTCFG;

#define DESC_LEN                16      /* 云台描述字符串长度 */
//云台协议表结构配置
typedef struct {
    DWORD dwType;
    /*解码器类型值*/
    BYTE byDescribe[DESC_LEN]; /*解码器的描述符，和8000中的一致*/
} NET_DVR_PTZ_PROTOCOL;

#define PTZ_PROTOCOL_NUM        200     /* 9000最大支持的云台协议数 */
typedef struct {
    DWORD dwSize;
    NET_DVR_PTZ_PROTOCOL struPtz[PTZ_PROTOCOL_NUM];
    /*最大200中PTZ协议*/
    DWORD dwPtzNum;
    /*有效的ptz协议数目，从0开始(即计算时加1)*/
    BYTE byRes[8];
} NET_DVR_PTZCFG, *LPNET_DVR_PTZCFG;

typedef struct tagNET_DVR_SDKLOCAL_CFG {
    BYTE byEnableAbilityParse;    //使用能力集解析库,0-不使用,1-使用,默认不使用
    BYTE byVoiceComMode;          //对讲模式，0-使用对讲库（默认），1-使用windows api模式
    BYTE byRes[382];
    BYTE byProtectKey[128];    //默认设置为0
} NET_DVR_SDKLOCAL_CFG, *LPNET_DVR_SDKLOCAL_CFG;

//硬盘状态
typedef struct {
    DWORD dwVolume;
    //硬盘的容量
    DWORD dwFreeSpace;
    //硬盘的剩余空间
    DWORD dwHardDiskStatic; //硬盘的状态,按位:1-休眠,2-不正常,3-休眠硬盘出错,4-未格式化, 5-未连接状态(网络硬盘),6-硬盘正在格式化
} NET_DVR_DISKSTATE, *LPNET_DVR_DISKSTATE;
//通道状态(9000扩展)
typedef struct {
    BYTE byRecordStatic; //通道是否在录像,0-不录像,1-录像
    BYTE bySignalStatic; //连接的信号状态,0-正常,1-信号丢失
    BYTE byHardwareStatic;
    //通道硬件状态,0-正常,1-异常,例如DSP死掉
    BYTE byRes1;        //保留
    DWORD dwBitRate;
    //实际码率
    DWORD dwLinkNum;
    //客户端连接的个数
    NET_DVR_IPADDR struClientIP[MAX_LINK];
    //客户端的IP地址
    DWORD dwIPLinkNum;
    //如果该通道为IP接入，那么表示IP接入当前的连接数
    BYTE byExceedMaxLink;        // 是否超出了单路6路连接数 0 - 未超出, 1-超出
    BYTE byRes[7];        // 保留字节
    DWORD dwChannelNo;    //当前的通道号，0xffffffff表示无效
} NET_DVR_CHANNELSTATE_V30, *LPNET_DVR_CHANNELSTATE_V30;
//DVR工作状态(9000扩展)
typedef struct {
    DWORD dwDeviceStatic;    //设备的状态,0-正常,1-CPU占用率太高,超过85%,2-硬件错误,例如串口死掉
    NET_DVR_DISKSTATE struHardDiskStatic[MAX_DISKNUM_V30];
    NET_DVR_CHANNELSTATE_V30 struChanStatic[MAX_CHANNUM_V30];
    //通道的状态
    BYTE byAlarmInStatic[MAX_ALARMIN_V30]; //报警端口的状态,0-没有报警,1-有报警
    BYTE byAlarmOutStatic[MAX_ALARMOUT_V30]; //报警输出端口的状态,0-没有输出,1-有报警输出
    DWORD dwLocalDisplay;
    //本地显示状态,0-正常,1-不正常
    BYTE byAudioChanStatus[MAX_AUDIO_V30];
    //表示语音通道的状态 0-未使用，1-使用中, 0xff无效
    BYTE byRes[10];
} NET_DVR_WORKSTATE_V30, *LPNET_DVR_WORKSTATE_V30;

typedef struct {
    DWORD dwEnabled;               //该端口是否被使能映射
    WORD wInternalPort;           //映射前的端口
    WORD wExternalPort;           //映射后的端口
    DWORD dwStatus;
    /*端口映射状态
                             0 未生效
                             1 未生效：映射源端口与目的端口需一致
                             2 未生效:  映射端口号已被使用
                             3 生效
                             */
    NET_DVR_IPADDR struNatExternalIp;       //映射后的外部地址
    NET_DVR_IPADDR struNatInternalIp;       //NAT路由器LAN IP地址
    BYTE byRes[16];               //保留
} NET_DVR_UPNP_PORT_STATE, *LPNET_DVR_UPNP_PORT_STATE;

#define UPNP_PORT_NUM            12      //upnp端口映射端口数目
typedef struct {
    NET_DVR_UPNP_PORT_STATE strUpnpPort[UPNP_PORT_NUM];     //端口映射状态,数组0 web server端口 数组1 管理端口 数组2 rtsp端口
    BYTE byRes[200];              //保留
} NET_DVR_UPNP_NAT_STATE, *LPNET_DVR_UPNP_NAT_STATE;

typedef enum _COMPRESSION_ABILITY_TYPE_ {
    COMPRESSION_STREAM_ABILITY = 0, //码流压缩类型
    MAIN_RESOLUTION_ABILITY = 1,    //主码流压缩分辨率
    SUB_RESOLUTION_ABILITY = 2,    //子码流压缩分辨率
    EVENT_RESOLUTION_ABILITY = 3,  //事件压缩参数分辨率
    FRAME_ABILITY = 4,                //帧率能力
    BITRATE_TYPE_ABILITY = 5,        //位率类型能力
    BITRATE_ABILITY = 6,            //位率上限
    THIRD_RESOLUTION_ABILITY = 7,   //三码流压缩分辨率
    STREAM_TYPE_ABILITY = 8,        //码流类型
    PIC_QUALITY_ABILITY = 9,         //图像质量
    INTERVAL_BPFRAME_ABILITY = 10,  //BP帧间隔
    VIDEO_ENC_ABILITY = 11,           //视频编码能力
    AUDIO_ENC_ABILITY = 12,           //音频编码能力
    VIDEO_ENC_COMPLEXITY_ABILITY = 13, //视频编码复杂度能力
    FORMAT_ABILITY = 14, //封装格式能力
} COMPRESSION_ABILITY_TYPE;

typedef struct tagNET_DVR_WIFIETHERNET {
    char sIpAddress[16];
    /*IP地址*/
    char sIpMask[16];
    /*掩码*/
    BYTE byMACAddr[MACADDR_LEN];
    /*物理地址，只用来显示*/
    BYTE bRes[2];
    DWORD dwEnableDhcp;
    /*是否启动dhcp  0不启动 1启动*/
    DWORD dwAutoDns;
    /*如果启动dhcp是否自动获取dns,0不自动获取 1自动获取；对于有线如果启动dhcp目前自动获取dns*/
    char sFirstDns[16];
    /*第一个dns域名*/
    char sSecondDns[16];
    /*第二个dns域名*/
    char sGatewayIpAddr[16];
    /* 网关地址*/
    BYTE bRes2[8];
} NET_DVR_WIFIETHERNET, *LPNET_DVR_WIFIETHERNET;
#define IW_ESSID_MAX_SIZE                         32
#define WIFI_WEP_MAX_KEY_COUNT                     4
#define WIFI_WEP_MAX_KEY_LENGTH                     33
#define WIFI_WPA_PSK_MAX_KEY_LENGTH                 63
#define WIFI_WPA_PSK_MIN_KEY_LENGTH                 8
#define WIFI_MAX_AP_COUNT                         20
typedef struct tagNET_DVR_WIFI_CFG_EX {
    NET_DVR_WIFIETHERNET struEtherNet;
    /*wifi网口*/
    char sEssid[IW_ESSID_MAX_SIZE];
    /*SSID*/
    DWORD dwMode;
    /* 0 mange 模式;1 ad-hoc模式，参见*/
    DWORD dwSecurity;
    /*0-不加密;1-WEP加密;2-WPA-personal; 3-WPA-enterprise;4-WPA2-personal;5-WPA2-enterprise */
    union {
        struct {
            DWORD dwAuthentication;
            /*0 -开放式 1-共享式*/
            DWORD dwKeyLength;
            /* 0 -64位；1- 128位；2-152位*/
            DWORD dwKeyType;
            /*0 16进制;1 ASCI */
            DWORD dwActive;
            /*0 索引：0---3表示用哪一个密钥*/
            char sKeyInfo[WIFI_WEP_MAX_KEY_COUNT][WIFI_WEP_MAX_KEY_LENGTH];
        } wep;
        struct {
            DWORD dwKeyLength;
            /*8-63个ASCII字符*/
            char sKeyInfo[WIFI_WPA_PSK_MAX_KEY_LENGTH];
            BYTE byEncryptType;  /*WPA/WPA2模式下加密类型,0-AES, 1-TKIP*/
        } wpa_psk;
        struct {
            BYTE byEncryptType;
            /*加密类型,0-AES, 1-TKIP*/
            BYTE byAuthType; //认证类型，0-EAP_TTLS,1-EAP_PEAP,2-EAP_TLS
            BYTE byRes[2];
            union {
                struct {
                    BYTE byEapolVersion; //EAPOL版本，0-版本1，1-版本2
                    BYTE byAuthType; //内部认证方式，0-PAP，1-MSCHAPV2
                    BYTE byRes1[2];
                    BYTE byAnonyIdentity[NAME_LEN]; //匿名身份
                    BYTE byUserName[NAME_LEN]; //用户名
                    BYTE byPassword[NAME_LEN]; //密码
                    BYTE byRes[44];
                } EAP_TTLS; //WPA-enterprise/WPA2-enterpris模式适用
                struct {
                    BYTE byEapolVersion; //EAPOL版本，0-版本1，1-版本2
                    BYTE byAuthType; //内部认证方式，0-GTC，1-MD5，2-MSCHAPV2
                    BYTE byPeapVersion; //PEAP版本，0-版本0，1-版本1
                    BYTE byPeapLabel; //PEAP标签，0-老标签，1-新标签
                    BYTE byAnonyIdentity[NAME_LEN]; //匿名身份
                    BYTE byUserName[NAME_LEN]; //用户名
                    BYTE byPassword[NAME_LEN]; //密码
                    BYTE byRes[44];
                } EAP_PEAP; //WPA-enterprise/WPA2-enterpris模式适用
                struct {
                    BYTE byEapolVersion; //EAPOL版本，0-版本1，1-版本2
                    BYTE byRes1[3];
                    BYTE byIdentity[NAME_LEN]; //身份
                    BYTE byPrivateKeyPswd[NAME_LEN]; //私钥密码
                    BYTE byRes[76];
                } EAP_TLS;
            } auth_param;
        } wpa_wpa2; //WPA-enterprise/WPA2-enterpris模式适用
    } key;
} NET_DVR_WIFI_CFG_EX, *LPNET_DVR_WIFI_CFG_EX;

typedef struct tagNET_DVR_AP_INFO {
    char sSsid[IW_ESSID_MAX_SIZE];
    DWORD dwMode;
    /* 0 mange 模式;1 ad-hoc模式，参见NICMODE */
    DWORD dwSecurity;
    /*0 不加密；1 wep加密；2 wpa-psk;3 wpa-Enterprise;4-WPA2_PSK参见WIFISECURITY*/
    DWORD dwChannel;
    /*1-11表示11个通道*/
    DWORD dwSignalStrength;
    /*0-100信号由最弱变为最强*/
    DWORD dwSpeed;               /*速率,单位是0.01mbps*/
} NET_DVR_AP_INFO, *LPNET_DVR_AP_INFO;

typedef struct tagNET_DVR_AP_INFO_LIST {
    DWORD dwSize;
    DWORD dwCount;
    /*无线AP数量，不超过20*/
    NET_DVR_AP_INFO struApInfo[WIFI_MAX_AP_COUNT];
} NET_DVR_AP_INFO_LIST, *LPNET_DVR_AP_INFO_LIST;

#define DESC_LEN_32          32   //描述字长度
#define MAX_NODE_NUM         256  //节点个数

typedef struct tagNET_DVR_DESC_NODE {
    int iValue;
    BYTE byDescribe[DESC_LEN_32]; //描述字段
    DWORD dwFreeSpace;           //获取磁盘列表专用,单位为M
    BYTE byRes[12];              //保留
} NET_DVR_DESC_NODE, *LPNET_DVR_DESC_NODE;
//能力列表
typedef struct tagNET_DVR_ABILITY_LIST {
    DWORD dwAbilityType;    //能力类型 COMPRESSION_ABILITY_TYPE
    BYTE byRes[32];        //保留字节
    DWORD dwNodeNum;        //能力结点个数
    NET_DVR_DESC_NODE struDescNode[MAX_NODE_NUM];  //描述参数
} NET_DVR_ABILITY_LIST, *LPNET_DVR_ABILITY_LIST;

#define MAX_ABILITYTYPE_NUM  12   //最大能力项
// 压缩参数能力列表
typedef struct tagNET_DVR_COMPRESSIONCFG_ABILITY {
    DWORD dwSize;            //结构长度
    DWORD dwAbilityNum;        //能力类型个数
    NET_DVR_ABILITY_LIST struAbilityNode[MAX_ABILITYTYPE_NUM]; //描述参数
} NET_DVR_COMPRESSIONCFG_ABILITY, *LPNET_DVR_COMPRESSIONCFG_ABILITY;

//报警输入参数配置(9000扩展)
typedef struct {
    DWORD dwSize;
    BYTE sAlarmInName[NAME_LEN];
    /* 名称 */
    BYTE byAlarmType;                //报警器类型,0：常开,1：常闭
    BYTE byAlarmInHandle;
    /* 是否处理 0-不处理 1-处理*/
    BYTE byChannel;                 // 报警输入触发智能识别通道
    BYTE byRes1[1];
    NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;
    /* 处理方式 */
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];
    //布防时间
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道
    BYTE byEnablePreset[MAX_CHANNUM_V30];
    /* 是否调用预置点 0-否,1-是*/
    BYTE byPresetNo[MAX_CHANNUM_V30];
    /* 调用的云台预置点序号,一个报警输入可以调用多个通道的云台预置点, 0xff表示不调用预置点。*/
    BYTE byRes2[192];
    /*保留*/
    BYTE byEnableCruise[MAX_CHANNUM_V30];
    /* 是否调用巡航 0-否,1-是*/
    BYTE byCruiseNo[MAX_CHANNUM_V30];
    /* 巡航 */
    BYTE byEnablePtzTrack[MAX_CHANNUM_V30];
    /* 是否调用轨迹 0-否,1-是*/
    BYTE byPTZTrack[MAX_CHANNUM_V30];
    /* 调用的云台的轨迹序号 */
    BYTE byRes3[16];
} NET_DVR_ALARMINCFG_V30, *LPNET_DVR_ALARMINCFG_V30;

//DVR报警输出(9000扩展)
typedef struct {
    DWORD dwSize;
    BYTE sAlarmOutName[NAME_LEN];
    /* 名称 */
    DWORD dwAlarmOutDelay;    /* 输出保持时间(-1为无限，手动关闭) */
    //0-5秒,1-10秒,2-30秒,3-1分钟,4-2分钟,5-5分钟,6-10分钟,7-手动
    NET_DVR_SCHEDTIME struAlarmOutTime[MAX_DAYS][MAX_TIMESEGMENT_V30];
    /* 报警输出激活时间段 */
    BYTE byRes[16];
} NET_DVR_ALARMOUTCFG_V30, *LPNET_DVR_ALARMOUTCFG_V30;

//通道解码器(云台)参数配置(9000扩展)
typedef struct {
    DWORD dwSize;
    DWORD dwBaudRate;
    //波特率(bps)，0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k;
    BYTE byDataBit;
    // 数据有几位 0－5位，1－6位，2－7位，3－8位;
    BYTE byStopBit;
    // 停止位 0－1位，1－2位;
    BYTE byParity;
    // 校验 0－无校验，1－奇校验，2－偶校验;
    BYTE byFlowcontrol;
    // 0－无，1－软流控,2-硬流控
    WORD wDecoderType;
    //解码器类型, 从0开始，对应ptz协议列表从NET_DVR_IPC_PROTO_LIST得到
    WORD wDecoderAddress;
    /*解码器地址:0 - 255*/
    BYTE bySetPreset[MAX_PRESET_V30];
    /* 预置点是否设置,0-没有设置,1-设置*/
    BYTE bySetCruise[MAX_CRUISE_V30];
    /* 巡航是否设置: 0-没有设置,1-设置 */
    BYTE bySetTrack[MAX_TRACK_V30];            /* 轨迹是否设置,0-没有设置,1-设置*/
} NET_DVR_DECODERCFG_V30, *LPNET_DVR_DECODERCFG_V30;

#define DEV_TYPE_NAME_LEN        24      //设备类型名称长度
//DVR设备参数
typedef struct {
    DWORD dwSize;
    BYTE sDVRName[NAME_LEN];     //DVR名称
    DWORD dwDVRID;                //DVR ID,用于遥控器 //V1.4(0-99), V1.5(0-255)
    DWORD dwRecycleRecord;        //是否循环录像,0:不是; 1:是
    //以下不可更改
    BYTE sSerialNumber[SERIALNO_LEN];  //序列号
    DWORD dwSoftwareVersion;            //软件版本号,高16位是主版本,低16位是次版本
    DWORD dwSoftwareBuildDate;            //软件生成日期,0xYYYYMMDD
    DWORD dwDSPSoftwareVersion;            //DSP软件版本,高16位是主版本,低16位是次版本
    DWORD dwDSPSoftwareBuildDate;        // DSP软件生成日期,0xYYYYMMDD
    DWORD dwPanelVersion;                // 前面板版本,高16位是主版本,低16位是次版本
    DWORD dwHardwareVersion;    // 硬件版本,高16位是主版本,低16位是次版本
    BYTE byAlarmInPortNum;        //DVR报警输入个数
    BYTE byAlarmOutPortNum;        //DVR报警输出个数
    BYTE byRS232Num;            //DVR 232串口个数
    BYTE byRS485Num;            //DVR 485串口个数
    BYTE byNetworkPortNum;        //网络口个数
    BYTE byDiskCtrlNum;            //DVR 硬盘控制器个数
    BYTE byDiskNum;                //DVR 硬盘个数
    BYTE byDVRType;                //DVR类型, 1:DVR 2:ATM DVR 3:DVS ......
    BYTE byChanNum;                //DVR 通道个数
    BYTE byStartChan;            //起始通道号,例如DVS-1,DVR - 1
    BYTE byDecordChans;            //DVR 解码路数
    BYTE byVGANum;                //VGA口的个数
    BYTE byUSBNum;                //USB口的个数
    BYTE byAuxoutNum;            //辅口的个数
    BYTE byAudioNum;            //语音口的个数
    BYTE byIPChanNum;            //最大数字通道数 低8位，高8位见byHighIPChanNum
    BYTE byZeroChanNum;            //零通道编码个数
    BYTE bySupport;        //能力，位与结果为0表示不支持，1表示支持，
    //bySupport & 0x1, 表示是否支持智能搜索
    //bySupport & 0x2, 表示是否支持备份
    //bySupport & 0x4, 表示是否支持压缩参数能力获取
    //bySupport & 0x8, 表示是否支持多网卡
    //bySupport & 0x10, 表示支持远程SADP
    //bySupport & 0x20, 表示支持Raid卡功能
    //bySupport & 0x40, 表示支持IPSAN搜索
    //bySupport & 0x80, 表示支持rtp over rtsp
    BYTE byEsataUseage;        //Esata的默认用途，0-默认备份，1-默认录像
    BYTE byIPCPlug;            //0-关闭即插即用，1-打开即插即用
    BYTE byStorageMode;        //0-盘组模式,1-磁盘配额, 2抽帧模式
    BYTE bySupport1;        //能力，位与结果为0表示不支持，1表示支持
    //bySupport1 & 0x1, 表示是否支持snmp v30
    //bySupport1 & 0x2, 支持区分回放和下载
    //bySupport1 & 0x4, 是否支持布防优先级
    //bySupport1 & 0x8, 智能设备是否支持布防时间段扩展
    //bySupport1 & 0x10, 表示是否支持多磁盘数（超过33个）
    //bySupport1 & 0x20, 表示是否支持rtsp over http
    WORD wDevType;
    //设备型号
    BYTE byDevTypeName[DEV_TYPE_NAME_LEN];
    //设备型号名称
    BYTE bySupport2; //能力集扩展，位与结果为0表示不支持，1表示支持
    //bySupport2 & 0x1, 表示是否支持扩展的OSD字符叠加(终端和抓拍机扩展区分)
    BYTE byAnalogAlarmInPortNum; //模拟报警输入个数
    BYTE byStartAlarmInNo;    //模拟报警输入起始号
    BYTE byStartAlarmOutNo;  //模拟报警输出起始号
    BYTE byStartIPAlarmInNo;  //IP报警输入起始号  0-无效
    BYTE byStartIPAlarmOutNo; //IP报警输出起始号 0-无效
    BYTE byHighIPChanNum;     //数字通道个数，高8位
    BYTE byRes2[9];            //保留
} NET_DVR_DEVICECFG_V40, *LPNET_DVR_DEVICECFG_V40;

typedef struct tagNET_DVR_IPSERVER_STREAM {
    BYTE byEnable;   // 是否在线
    BYTE byRes[3];               // 保留字节
    NET_DVR_IPADDR struIPServer;    //IPServer 地址
    WORD wPort;                  //IPServer 端口
    WORD wDvrNameLen;            // DVR 名称长度
    BYTE byDVRName[NAME_LEN];    // DVR名称
    WORD wDVRSerialLen;          // 序列号长度
    WORD byRes1[2];              // 保留字节
    BYTE byDVRSerialNumber[SERIALNO_LEN];    // DVR序列号长度
    BYTE byUserName[NAME_LEN];   // DVR 登陆用户名
    BYTE byPassWord[PASSWD_LEN]; // DVR登陆密码
    BYTE byChannel;              // DVR 通道
    BYTE byRes2[11];             //  保留字节
} NET_DVR_IPSERVER_STREAM, *LPNET_DVR_IPSERVER_STREAM;

//流媒体服务器基本配置
typedef struct tagNET_DVR_STREAM_MEDIA_SERVER_CFG {
    BYTE byValid;
    /*是否可用*/
    BYTE byRes1[3];
    NET_DVR_IPADDR struDevIP;
    WORD wDevPort;
    /*流媒体服务器端口*/
    BYTE byTransmitType;
    /*传输协议类型 0-TCP，1-UDP*/
    BYTE byRes2[69];
} NET_DVR_STREAM_MEDIA_SERVER_CFG, *LPNET_DVR_STREAM_MEDIA_SERVER_CFG;

//设备通道信息
typedef struct tagNET_DVR_DEV_CHAN_INFO {
    NET_DVR_IPADDR struIP;            //DVR IP地址
    WORD wDVRPort;                //端口号
    BYTE byChannel;                //通道号
    BYTE byTransProtocol;        //传输协议类型0-TCP，1-UDP
    BYTE byTransMode;            //传输码流模式 0－主码流 1－子码流
    BYTE byFactoryType;
    /*前端设备厂家类型,通过接口获取*/
    BYTE byDeviceType; //设备类型(视频综合平台智能板使用)，1-解码器（此时根据视频综合平台能力集中byVcaSupportChanMode字段来决定是使用解码通道还是显示通道），2-编码器
    BYTE byDispChan;
    //显示通道号,智能配置使用
    BYTE bySubDispChan;
    //显示通道子通道号，智能配置时使用
    BYTE byResolution;    //; 1-CIF 2-4CIF 3-720P 4-1080P 5-500w大屏控制器使用，大屏控制器会根据该参数分配解码资源
    BYTE byRes[2];
    BYTE byDomain[MAX_DOMAIN_NAME];    //设备域名
    BYTE sUserName[NAME_LEN];    //监控主机登陆帐号
    BYTE sPassword[PASSWD_LEN];    //监控主机密码
} NET_DVR_DEV_CHAN_INFO, *LPNET_DVR_DEV_CHAN_INFO;

//直接通过流媒体取流
typedef struct tagNET_DVR_PU_STREAM_CFG {
    DWORD dwSize;
    NET_DVR_STREAM_MEDIA_SERVER_CFG struStreamMediaSvrCfg;
    NET_DVR_DEV_CHAN_INFO struDevChanInfo;
} NET_DVR_PU_STREAM_CFG, *LPNET_DVR_PU_STREAM_CFG;

typedef struct tagNET_DVR_DDNS_STREAM_CFG {
    BYTE byEnable;   // 是否启用
    BYTE byRes1[3];
    NET_DVR_IPADDR struStreamServer;            //流媒体服务器地址
    WORD wStreamServerPort;           //流媒体服务器端口
    BYTE byStreamServerTransmitType;  //流媒体传输协议类型 0-TCP，1-UDP
    BYTE byRes2;
    NET_DVR_IPADDR struIPServer;          //IPSERVER地址
    WORD wIPServerPort;        //IPserver端口号
    BYTE byRes3[2];
    BYTE sDVRName[NAME_LEN];   //DVR名称
    WORD wDVRNameLen;            // DVR名称长度
    WORD wDVRSerialLen;          // 序列号长度
    BYTE sDVRSerialNumber[SERIALNO_LEN];    // DVR序列号
    BYTE sUserName[NAME_LEN];   // DVR 登陆用户名
    BYTE sPassWord[PASSWD_LEN]; // DVR登陆密码
    WORD wDVRPort;   //DVR端口号
    BYTE byRes4[2];
    BYTE byChannel;              // DVR 通道
    BYTE byTransProtocol; //传输协议类型0-TCP，1-UDP
    BYTE byTransMode; //传输码流模式 0－主码流 1－子码流
    BYTE byFactoryType; //前端设备厂家类型,通过接口获取
} NET_DVR_DDNS_STREAM_CFG, *LPNET_DVR_DDNS_STREAM_CFG;

typedef struct tagNET_DVR_PU_STREAM_URL {
    BYTE byEnable;
    BYTE strURL[240];
    BYTE byTransPortocol; // 传输协议类型 0-tcp  1-UDP
    WORD wIPID;  //设备ID号，wIPID = iDevInfoIndex + iGroupNO*64 +1
    BYTE byChannel;  //通道号
    BYTE byRes[7];
} NET_DVR_PU_STREAM_URL, *LPNET_DVR_PU_STREAM_URL;

typedef struct tagNET_DVR_HKDDNS_STREAM {
    BYTE byEnable;                 // 是否在线
    BYTE byRes[3];               // 保留字节
    BYTE byDDNSDomain[64];        // hiDDNS服务器
    WORD wPort;                  // hiDDNS 端口
    WORD wAliasLen;              // 别名长度
    BYTE byAlias[NAME_LEN];         // 别名
    WORD wDVRSerialLen;          // 序列号长度
    BYTE byRes1[2];              // 保留字节
    BYTE byDVRSerialNumber[SERIALNO_LEN];    // DVR序列号
    BYTE byUserName[NAME_LEN];   // DVR 登陆用户名
    BYTE byPassWord[PASSWD_LEN]; // DVR登陆密码
    BYTE byChannel;              // DVR通道
    BYTE byRes2[11];             // 保留字
} NET_DVR_HKDDNS_STREAM, *LPNET_DVR_HKDDNS_STREAM;

typedef struct tagNET_DVR_IPCHANINFO_V40 {
    BYTE byEnable;
    /* 该通道是否在线 */
    BYTE byRes1;
    WORD wIPID;                  //IP设备ID
    DWORD dwChannel;                //通道号
    BYTE byTransProtocol;        //传输协议类型0-TCP，1-UDP
    BYTE byTransMode;            //传输码流模式 0－主码流 1－子码流
    BYTE byFactoryType;
    /*前端设备厂家类型,通过接口获取*/
    BYTE byRes[241];
} NET_DVR_IPCHANINFO_V40, *LPNET_DVR_IPCHANINFO_V40;

typedef union tagNET_DVR_GET_STREAM_UNION {
    NET_DVR_IPCHANINFO struChanInfo;
    /*IP通道信息*/
    NET_DVR_IPSERVER_STREAM struIPServerStream;  // IPServer去流
    NET_DVR_PU_STREAM_CFG struPUStream;     //  通过前端设备获取流媒体去流
    NET_DVR_DDNS_STREAM_CFG struDDNSStream;     //通过IPServer和流媒体取流
    NET_DVR_PU_STREAM_URL struStreamUrl;        //通过流媒体到url取流
    NET_DVR_HKDDNS_STREAM struHkDDNSStream;   //通过hiDDNS去取流
    NET_DVR_IPCHANINFO_V40 struIPChan; //直接从设备取流（扩展）
} NET_DVR_GET_STREAM_UNION, *LPNET_DVR_GET_STREAM_UNION;

typedef enum {
    NET_SDK_IP_DEVICE = 0,
    NET_SDK_STREAM_MEDIA,
    NET_SDK_IPSERVER,
    NET_SDK_DDNS_STREAM_CFG,
    NET_SDK_STREAM_MEDIA_URL,
    NET_SDK_HKDDNS,
    NET_SDK_IP_DEVICE_ADV
} GET_STREAM_TYPE;

typedef struct tagNET_DVR_STREAM_MODE {
    BYTE byGetStreamType; //取流方式GET_STREAM_TYPE，0-直接从设备取流，1-从流媒体取流、2-通过IPServer获得ip地址后取流,3.通过IPServer找到设备，再通过流媒体去设备的流
    //4-通过流媒体由URL去取流,5-通过hkDDNS取流，6-直接从设备取流(扩展)，使用NET_DVR_IPCHANINFO_V40结构
    BYTE byRes[3];        //保留字节
    NET_DVR_GET_STREAM_UNION uGetStream;    // 不同取流方式结构体
} NET_DVR_STREAM_MODE, *LPNET_DVR_STREAM_MODE;

//扩展IP接入配置设备
typedef struct tagNET_DVR_IPPARACFG_V40 {
    DWORD dwSize;
    /* 结构大小 */
    DWORD dwGroupNum;                    //	 设备支持的总组数
    DWORD dwAChanNum;                    //最大模拟通道个数
    DWORD dwDChanNum;                  //数字通道个数
    DWORD dwStartDChan;                    //起始数字通道
    BYTE byAnalogChanEnable[MAX_CHANNUM_V30];
    /* 模拟通道是否启用，从低到高表示1-64通道，0表示无效 1有效 */
    NET_DVR_IPDEVINFO_V31 struIPDevInfo[MAX_IP_DEVICE_V40];
    /* IP设备 */
    NET_DVR_STREAM_MODE struStreamMode[MAX_CHANNUM_V30];
    BYTE byRes2[20];                 // 保留字节
} NET_DVR_IPPARACFG_V40, *LPNET_DVR_IPPARACFG_V40;

//ntp
typedef struct {
    BYTE sNTPServer[64];
    /* Domain Name or IP addr of NTP server */
    WORD wInterval;
    /* adjust time interval(hours) */
    BYTE byEnableNTP;
    /* enable NPT client 0-no，1-yes*/
    signed char cTimeDifferenceH;
    /* 与国际标准时间的 小时偏移-12 ... +13 */
    signed char cTimeDifferenceM;
    /* 与国际标准时间的 分钟偏移0, 30, 45*/
    BYTE res1;
    WORD wNtpPort;
    /* ntp server port 9000新增 设备默认为123*/
    BYTE res2[8];
} NET_DVR_NTPPARA, *LPNET_DVR_NTPPARA;

//时间段录像参数配置(子结构)
typedef struct {
    NET_DVR_SCHEDTIME struRecordTime;
    BYTE byRecordType;    //0:定时录像，1:移动侦测，2:报警录像，3:动测|报警，4:动测&报警, 5:命令触发, 6: 智能录像,10-PIR报警，11-无线报警，12-呼救报警，13-所有报警,14-智能交通事件，15越界侦测，16区域入侵侦测，17音频异常侦测
    char reservedData[3];
} NET_DVR_RECORDSCHED, *LPNET_DVR_RECORDSCHED;

//全天录像参数配置(子结构)
typedef struct {
    WORD wAllDayRecord;
    /* 是否全天录像 0-否 1-是*/
    BYTE byRecordType;
    /* 录象类型 0:定时录像，1:移动侦测，2:报警录像，3:动测|报警，4:动测&报警 5:命令触发, 6: 智能录像,10-PIR报警，11-无线报警，12-呼救报警，13-移动|报警输入|PIR|无线报警|呼救报警,14-智能交通事件,15-越界侦测,16-区域入侵,17-声音异常,18-场景变更侦测,19-智能侦测（越界侦测|区域入侵|进入区域|离开区域|人脸识别）*/
    char reservedData;
} NET_DVR_RECORDDAY, *LPNET_DVR_RECORDDAY;

//通道录像参数配置(9000扩展)
typedef struct {
    DWORD dwSize;
    DWORD dwRecord;
    /*是否录像 0-否 1-是*/
    NET_DVR_RECORDDAY struRecAllDay[MAX_DAYS];
    NET_DVR_RECORDSCHED struRecordSched[MAX_DAYS][MAX_TIMESEGMENT_V30];
    DWORD dwRecordTime;
    /* 录象延时长度 0-5秒， 1-10秒， 2-30秒， 3-1分钟， 4-2分钟， 5-5分钟， 6-10分钟*/
    DWORD dwPreRecordTime;
    /* 预录时间 0-不预录 1-5秒 2-10秒 3-15秒 4-20秒 5-25秒 6-30秒 7-0xffffffff(尽可能预录) */
    DWORD dwRecorderDuration;
    /* 录像保存的最长时间 */
    BYTE byRedundancyRec;
    /*是否冗余录像,重要数据双备份：0/1*/
    BYTE byAudioRec;
    /*录像时复合流编码时是否记录音频数据：国外有此法规*/
    BYTE byStreamType;  // 0:主码流 1：子码流
    BYTE byPassbackRecord;  // 0:不回传录像 1：回传录像
    WORD wLockDuration;  // 录像锁定时长，单位小时 0表示不锁定，0xffff表示永久锁定，录像段的时长大于锁定的持续时长的录像，将不会锁定
    BYTE byRecordBackup;  // 0:录像不存档 1：录像存档
    BYTE bySVCLevel;    //SVC抽帧类型：0-不抽，1-抽二分之一 2-抽四分之三
    BYTE byReserve[4];
} NET_DVR_RECORD_V30, *LPNET_DVR_RECORD_V30;

//视频参数配置
typedef struct tagNET_DVR_VIDEOEFFECT {
    BYTE byBrightnessLevel;
    /*0-100*/
    BYTE byContrastLevel;
    /*0-100*/
    BYTE bySharpnessLevel;
    /*0-100*/
    BYTE bySaturationLevel;
    /*0-100*/
    BYTE byHueLevel;
    /*0-100,（保留）*/
    BYTE byEnableFunc; //使能，按位表示，bit0-SMART IR(防过曝)，bit1-低照度,bit2-强光抑制使能，0-否，1-是
    BYTE byLightInhibitLevel; //强光抑制等级，[1-3]表示等级
    BYTE byGrayLevel; //灰度值域，0-[0-255]，1-[16-235]
} NET_DVR_VIDEOEFFECT, *LPNET_DVR_VIDEOEFFECT;

//wifi连接状态
typedef struct tagNET_DVR_WIFI_CONNECT_STATUS {
    DWORD dwSize;
    BYTE byCurStatus;    //1-已连接，2-未连接，3-正在连接
    BYTE byRes1[3];        //保留
    DWORD dwErrorCode;    // byCurStatus = 2时有效,1-用户名或密码错误,2-无此路由器,3-未知错误
    BYTE byRes[244];
} NET_DVR_WIFI_CONNECT_STATUS, *LPNET_DVR_WIFI_CONNECT_STATUS;

//零通道压缩配置参数
typedef struct tagNET_DVR_ZEROCHANCFG {
    DWORD dwSize;            //结构长度
    BYTE byEnable;            //0-停止零通道编码，1-表示启用零通道编码
    BYTE byRes1[3];            //保留
    DWORD dwVideoBitrate;    //视频码率 0-保留 1-16K(保留) 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
    // 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
    //最高位(31位)置成1表示是自定义码流, 0-30位表示码流值(MIN-32K MAX-8192K)。
    DWORD dwVideoFrameRate;    //帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20, //V2.0增加14-15, 15-18, 16-22;
    BYTE byRes2[32];        //保留
} NET_DVR_ZEROCHANCFG, *LPNET_DVR_ZEROCHANCFG;

#define MAX_AUX_ALARM_NUM 8 //最大辅助报警个数
#define MAX_WIRELESS_ALARM_NUM 8 //最大无线报警个数
typedef enum _IPC_AUX_ALARM_TYPE_ {
    IPC_AUXALARM_UNKNOW = 0, //未知
    IPC_AUXALARM_PIR = 1, //PIR报警
    IPC_AUXALARM_WIRELESS = 2,   //无线报警
    IPC_AUXALARM_CALLHELP = 3  //呼救报警
} IPC_AUX_ALARM_TYPE;

typedef struct tagNET_IPC_PIR_ALARMCFG_EX {
    BYTE byAlarmName[NAME_LEN];
    /* 报警名称 */
    BYTE byAlarmHandle;
    /* 是否处理 0-不处理 1-处理*/
    BYTE byRes1[3];
    NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;
    /* 处理方式 */
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];
    BYTE byRes[1464];
} NET_IPC_PIR_ALARMCFG_EX, *LPNET_IPC_PIR_ALARMCFG_EX;

//呼救报警
typedef struct tagNET_IPC_CALLHELP_ALARMCFG {
    BYTE byAlarmHandle;
    /* 是否处理 0-不处理 1-处理*/
    BYTE byRes1[3];
    NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;
    /* 处理方式 */
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道
    BYTE byRes[64];
} NET_IPC_CALLHELP_ALARMCFG, *LPNET_IPC_CALLHELP_ALARMCFG;

typedef struct tagNET_IPC_SINGLE_WIRELESS_ALARMCFG {
    BYTE byAlarmName[NAME_LEN];
    /* 报警名称 */
    BYTE byAlarmHandle;
    /* 是否处理 0-不处理 1-处理*/
    BYTE byID; //无线报警ID，1-8
    BYTE byRes1[2];
    NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;
    /* 处理方式 */
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道
    BYTE byRes[32];
} NET_IPC_SINGLE_WIRELESS_ALARMCFG, *LPNET_IPC_SINGLE_WIRELESS_ALARMCFG;

typedef struct tagNET_IPC_WIRELESS_ALARMCFG {
    NET_IPC_SINGLE_WIRELESS_ALARMCFG struWirelessAlarm[MAX_WIRELESS_ALARM_NUM]; //单个无线报警参数
    BYTE byRes[32];
} NET_IPC_WIRELESS_ALARMCFG, *LPNET_IPC_WIRELESS_ALARMCFG;

typedef union tagNET_IPC_AUX_ALARMCFG_UNION {
    DWORD uLen[472];
    NET_IPC_PIR_ALARMCFG_EX struPIRAlarm; //PIR报警参数
    NET_IPC_WIRELESS_ALARMCFG struWirelessAlarm; //无线报警参数
    NET_IPC_CALLHELP_ALARMCFG struCallHelpAlarm; //呼救报警参数
} NET_IPC_AUX_ALARMCFG_UNION, *LPNET_IPC_AUX_ALARMCFG_UNION;

typedef struct tagNET_IPC_SINGLE_AUX_ALARMCFG {
    BYTE byAlarmType;       //报警器类型，详见IPC_AUX_ALARM_TYPE
    BYTE byRes1[3];
    NET_IPC_AUX_ALARMCFG_UNION uAlarm; //报警参数
    BYTE byRes[16];
} NET_IPC_SINGLE_AUX_ALARMCFG, *LPNET_IPC_SINGLE_AUX_ALARMCFG;

typedef struct tagNET_IPC_AUX_ALARMCFG {
    DWORD dwSize;
    NET_IPC_SINGLE_AUX_ALARMCFG struAlarm[MAX_AUX_ALARM_NUM]; //报警参数
    BYTE byRes[64];
} NET_IPC_AUX_ALARMCFG, *LPNET_IPC_AUX_ALARMCFG;
/********************************SDK接口*********************************/
//初始化
NET_DVR_API BOOL __stdcall NET_DVR_Init();
NET_DVR_API BOOL __stdcall NET_DVR_Cleanup();

//超时重连设置
NET_DVR_API BOOL __stdcall NET_DVR_SetConnectTime(DWORD dwWaitTime = 5000, DWORD dwTryTimes = 3);
NET_DVR_API BOOL __stdcall NET_DVR_SetReconnect(DWORD dwInterval = 30000, BOOL bEnableRecon = TRUE);

    //NET_DVR_API BOOL __stdcall NET_DVR_SetConnectTime(DWORD dwWaitTime , DWORD dwTryTimes);
    //NET_DVR_API BOOL __stdcall NET_DVR_SetReconnect(DWORD dwInterval , BOOL bEnableRecon);

    
//获取SDK版本
NET_DVR_API DWORD __stdcall NET_DVR_GetSDKVersion();
NET_DVR_API DWORD __stdcall NET_DVR_GetSDKBuildVersion();

//错误信息回调
NET_DVR_API BOOL __stdcall NET_DVR_SetExceptionCallBack_V30(UINT reserved1, void *reserved2, void (CALLBACK *fExceptionCallBack)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser), void *pUser);

//登陆注销
NET_DVR_API LONG __stdcall NET_DVR_Login_V30(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
NET_DVR_API BOOL __stdcall NET_DVR_Logout_V30(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_Logout(LONG lUserID);

//获取错误信息
NET_DVR_API DWORD __stdcall NET_DVR_GetLastError();
NET_DVR_API char *__stdcall NET_DVR_GetErrorMsg(LONG *pErrorNo = NULL);

//预览
typedef void (CALLBACK *REALDATACALLBACK)(LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_RealPlay_V30(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser) = NULL, void *pUser = NULL, BOOL bBlocked = FALSE);



    
    NET_DVR_API BOOL __stdcall NET_DVR_StopRealPlay(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SaveRealData(LONG lRealHandle, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopSaveRealData(LONG lRealHandle);
NET_DVR_API LONG __stdcall NET_DVR_ZeroStartPlay(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, REALDATACALLBACK fRealDataCallBack_V30 = NULL, void *pUser = NULL, BOOL bBlocked = TRUE);
 NET_DVR_API BOOL __stdcall NET_DVR_ZeroStopPlay(LONG lPlayHandle);


//主子码流强制I帧
NET_DVR_API BOOL __stdcall NET_DVR_MakeKeyFrame(LONG lUserID, LONG lChannel);
NET_DVR_API BOOL __stdcall NET_DVR_MakeKeyFrameSub(LONG lUserID, LONG lChannel);

//视频效果参数
NET_DVR_API BOOL __stdcall NET_DVR_ClientSetVideoEffect(LONG lRealHandle, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_ClientGetVideoEffect(LONG lRealHandle, DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue);

//基本操作
NET_DVR_API BOOL __stdcall NET_DVR_RebootDVR(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_ShutDownDVR(LONG lUserID);
//远程控制设备端手动录像
NET_DVR_API BOOL __stdcall NET_DVR_StartDVRRecord(LONG lUserID, LONG lChannel, LONG lRecordType);
NET_DVR_API BOOL __stdcall NET_DVR_StopDVRRecord(LONG lUserID, LONG lChannel);
//布防接收报警信息
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan_V30(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CloseAlarmChan_V30(LONG lAlarmHandle);
typedef void (CALLBACK *MSGCallBack)(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessageCallBack_V30(MSGCallBack fMessageCallBack, void *pUser);

//PTZ控制
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset(LONG lRealHandle, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset_Other(LONG lUserID, LONG lChannel, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl_EX(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset_EX(LONG lRealHandle, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise(LONG lRealHandle, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise_EX(LONG lRealHandle, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack(LONG lRealHandle, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack_Other(LONG lUserID, LONG lChannel, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack_EX(LONG lRealHandle, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed_EX(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);

NET_DVR_API BOOL __stdcall NET_DVR_GetPTZProtocol(LONG lUserID, NET_DVR_PTZCFG *pPtzcfg);

//云台图象区域选择放大或缩小
NET_DVR_API BOOL __stdcall NET_DVR_PTZSelZoomIn(LONG lRealHandle, LPNET_DVR_POINT_FRAME pStruPointFrame);
NET_DVR_API BOOL __stdcall NET_DVR_PTZSelZoomIn_EX(LONG lUserID, LONG lChannel, LPNET_DVR_POINT_FRAME pStruPointFrame);

//语音转发
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_MR_V30(LONG lUserID, DWORD dwVoiceChan, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void *pUser), void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_VoiceComSendData(LONG lVoiceComHandle, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_StopVoiceCom(LONG lVoiceComHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetCurrentAudioCompress(LONG lUserID, LPNET_DVR_COMPRESSION_AUDIO lpCompressAudio);

//触发报警输出
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmOut_V30(LONG lUserID, LPNET_DVR_ALARMOUTSTATUS_V30 lpAlarmOutState);
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmOut(LONG lUserID, LONG lAlarmOutPort, LONG lAlarmOutStatic);

//参数配置
#define NET_DVR_GET_DEVICECFG            100
#define NET_DVR_SET_DEVICECFG            101
#define NET_DVR_GET_DEVICECFG_V40        1100

#define NET_DVR_GET_TIMECFG                118
#define NET_DVR_SET_TIMECFG                119

#define NET_DVR_GET_NTPCFG                224
#define NET_DVR_SET_NTPCFG                225

#define NET_DVR_GET_AP_INFO_LIST        305
#define NET_DVR_SET_WIFI_CFG            306
#define NET_DVR_GET_WIFI_CFG            307
#define NET_DVR_GET_WIFI_STATUS            310

#define NET_DVR_GET_NETCFG_V30            1000
#define NET_DVR_SET_NETCFG_V30            1001

#define NET_DVR_GET_PICCFG_V30            1002
#define NET_DVR_SET_PICCFG_V30            1003

#define NET_DVR_GET_RECORDCFG_V30        1004
#define NET_DVR_SET_RECORDCFG_V30        1005

#define NET_DVR_GET_ALARMINCFG_V30        1024
#define NET_DVR_SET_ALARMINCFG_V30        1025
#define NET_DVR_GET_ALARMOUTCFG_V30        1026
#define NET_DVR_SET_ALARMOUTCFG_V30        1027

#define NET_DVR_GET_COMPRESSCFG_V30        1040
#define NET_DVR_SET_COMPRESSCFG_V30        1041

#define NET_DVR_GET_DECODERCFG_V30        1042
#define NET_DVR_SET_DECODERCFG_V30        1043

#define NET_DVR_GET_IPALARMOUTCFG       1052

#define NET_DVR_GET_COMPRESSCFG_AUD        1058

#define NET_DVR_GET_IPPARACFG_V31       1060
#define NET_DVR_SET_IPPARACFG_V31       1061
#define NET_DVR_GET_IPPARACFG_V40        1062
#define NET_DVR_SET_IPPARACFG_V40        1063

#define NET_DVR_GET_ZEROCHANCFG            1102
#define NET_DVR_SET_ZEROCHANCFG            1103

#define NET_IPC_GET_AUX_ALARMCFG        3209
#define NET_IPC_SET_AUX_ALARMCFG        3210


NET_DVR_API BOOL __stdcall NET_DVR_GetDVRConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize);

NET_DVR_API BOOL __stdcall NET_DVR_GetDVRWorkState_V30(LONG lUserID, LPNET_DVR_WORKSTATE_V30 lpWorkState);

NET_DVR_API BOOL __stdcall NET_DVR_GetUpnpNatState(LONG lUserID, LPNET_DVR_UPNP_NAT_STATE lpState);
//文件检索
NET_DVR_API LONG __stdcall NET_DVR_FindFile_V30(LONG lUserID, NET_DVR_FILECOND *pFindCond);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFile_V30(LONG lFindHandle, LPNET_DVR_FINDDATA_V30 lpFindData);
NET_DVR_API BOOL  __stdcall NET_DVR_FindClose_V30(LONG lFindHandle);

//文件回放下载
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByName(LONG lUserID, char *sPlayBackFileName, HWND hWnd);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByTime(LONG lUserID, LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, HWND hWnd);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByName(LONG lUserID, char *sDVRFileName, char *sSavedFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByTime(LONG lUserID, LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, char *sSavedFileName);
NET_DVR_API BOOL  __stdcall NET_DVR_StopGetFile(LONG lFileHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetDownloadPos(LONG lFileHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetPlayBackPos(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayBack(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayDataCallBack_V40(LONG lPlayHandle, void(CALLBACK *fPlayDataCallBack_V40)(LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser), void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackControl_V40(LONG lPlayHandle, DWORD dwControlCode, LPVOID lpInBuffer = NULL, DWORD dwInLen = 0, LPVOID lpOutBuffer = NULL, DWORD *lpOutLen = NULL);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackSaveData(LONG lPlayHandle, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayBackSave(LONG lPlayHandle);

//IP Server
NET_DVR_API BOOL  __stdcall NET_DVR_GetDVRIPByResolveSvr_EX(char *sServerIP, WORD wServerPort, unsigned char *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char *sGetIP, DWORD *dwPort);

//JPEG抓图
NET_DVR_API BOOL __stdcall NET_DVR_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sPicFileName);
NET_DVR_API BOOL __stdcall NET_DVR_CaptureJPEGPicture_NEW(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sJpegPicBuffer, DWORD dwPicSize, LPDWORD lpSizeReturned);

//启用日志文件写入接口
NET_DVR_API BOOL __stdcall NET_DVR_SetLogToFile(DWORD nLogLevel = 0, char *strLogDir = NULL, BOOL bAutoDel = TRUE);

//透明通道设置
NET_DVR_API LONG __stdcall NET_DVR_SerialStart(LONG lUserID, LONG lSerialPort, void(CALLBACK *fSerialDataCallBack)(LONG lSerialHandle, char *pRecvDataBuffer, DWORD dwBufSize, DWORD dwUser), DWORD dwUser);
//485作为透明通道时，需要指明通道号，因为不同通道号485的设置可以不同(比如波特率)
NET_DVR_API BOOL __stdcall NET_DVR_SerialSend(LONG lSerialHandle, LONG lChannel, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_SerialStop(LONG lSerialHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SendTo232Port(LONG lUserID, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_SendToSerialPort(LONG lUserID, DWORD dwSerialPort, DWORD dwSerialIndex, char *pSendBuf, DWORD dwBufSize);
//SDK本地设置
NET_DVR_API BOOL __stdcall NET_DVR_SetSDKLocalConfig(LPNET_DVR_SDKLOCAL_CFG lpSdkLocalCfg);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKLocalConfig(LPNET_DVR_SDKLOCAL_CFG lpSdkLocalCfg);
NET_DVR_API BOOL  __stdcall NET_DVR_SetRecvTimeOut(DWORD nRecvTimeOut = 5000); //最小3000毫秒
//升级
NET_DVR_API LONG __stdcall NET_DVR_Upgrade(LONG lUserID, char *sFileName);
NET_DVR_API int __stdcall NET_DVR_GetUpgradeState(LONG lUpgradeHandle);
NET_DVR_API int __stdcall NET_DVR_GetUpgradeProgress(LONG lUpgradeHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetUpgradeStep(LONG lUpgradeHandle, LONG *pSubProgress);
NET_DVR_API BOOL __stdcall NET_DVR_CloseUpgradeHandle(LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetNetworkEnvironment(DWORD dwEnvironmentLevel);

#ifdef __cplusplus
}
#endif

#endif 

