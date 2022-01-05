/*
 * strToHex
 * 字符串到十六进制
 * Text 欲转换为十六进制的字符串
 * 返回 转换为十六进制的文本
 */
Api(const char*, strToHex, const char* Text);

/*
 * hexToStr
 * 十六进制到字符串
 * Hex 欲翻译为字符串的十六进制
 * 返回 翻译为字串符的十六进制文本
 */
Api(const char*, hexToStr, const char* Hex);

/*
 * apiVersion
 * 获取cgapi引擎版本
 * 返回 版本号
 */
Api(int32_t, apiVersion);

/*
 * _get_gamedata_dir
 * 获取游戏数据目录
 */
Api(const char*, _get_gamedata_dir);

/*
 * _get_init_dir
 * 获取初始化目录
 */
Api(const char*, _get_init_dir);

/*
 * CG_sendPrivateMsg
 * 发送私聊消息 - 普通
 * uID 接收消息的用户
 * msg 发送的消息
 */
Api(void, CG_sendPrivateMsg, const char* uID, const char* msg);

/*
 * CG_sendGroupMsg
 * 发送群聊消息 - 普通
 * gID 接收消息的群号
 * msg 发送的消息
 */
Api(void, CG_sendGroupMsg, const char* gID, const char* msg);

/*
 * CG_sendDiscussMsg
 * 发送讨论组消息 - 普通
 * DiscussID 接收消息的讨论组号
 * msg 发送的消息
 */
Api(void, CG_sendDiscussMsg, const char* DiscussID, const char* msg);

/*
 * CG_sendPrivateMsg
 * 发送私聊消息 - 高级
 * uID 接收/处理消息的用户
 * msg 发送的消息
 */
Api(void, CG_sendPrivateMsg_v2, const char* uID, const char* msg);

/*
 * CG_sendGroupMsg
 * 发送群聊消息 - 高级
 * uID 处理消息的用户
 * gID 接收消息的群号
 * msg 发送的消息
 */
Api(void, CG_sendGroupMsg_v2, const char* uID, const char* gID, const char* msg);

/*
 * CG_sendDiscussMsg
 * 发送讨论组消息 - 高级
 * uID 处理消息的用户
 * DiscussID 接收消息的讨论组号
 * msg 发送的消息
 */
Api(void, CG_sendDiscussMsg_v2, const char* uID, const char* DiscussID, const char* msg);

/*
 * CG_addLog_Debug
 * 输出日志 - 调试
 * Name 日志名称(标识)
 * msg 输出的日志信息
 */
Api(void, CG_addLog_Debug, const char* Name, const char* msg);

/*
 * CG_addLog_Info
 * 输出日志 - 信息
 * Name 日志名称(标识)
 * msg 输出的日志信息
 */
Api(void, CG_addLog_Info, const char* Name, const char* msg);

/*
 * CG_addLog_Warning
 * 输出日志 - 警告
 * Name 日志名称(标识)
 * msg 输出的日志信息
 */
Api(void, CG_addLog_Warning, const char* Name, const char* msg);

/*
 * CG_addLog_Error
 * 输出日志 - 错误
 * Name 日志名称(标识)
 * msg 输出的日志信息
 */
Api(void, CG_addLog_Error, const char* Name, const char* msg);

/*
 * _get_user_id
 * 获取登录的机器人QQ
 * 返回 机器人QQ号
 */
Api(const char*, _get_user_id);

/*
 * get_db_handle
 * 获取CakeGame主数据库连接句柄
 * 返回 数据库句柄
 */
Api(void*, get_db_handle);

/*
 * _judge_usable_function
 * 监测指定功能是否可用(一般用于指令函数初始判断)
 * func 功能名称(注意：非触发格式)
 * userid 来源玩家
 * fromid 来源群号或讨论组(私聊则为空)
 * 返回 返回不可用的具体信息，如果返回字符串长度为0则表示可用
 */
Api(const char*, _judge_usable_function, const char* func, const char* userid, const char* fromid);

/*
 * _judge_weak_user
 * 判断玩家是否处于虚弱状态
 * UserID 玩家ID
 * 返回 虚弱剩余时间(分),返回0代表不是虚弱状态.
 */
Api(int32_t, _judge_weak_user, const char* UserID);

/*
 * Global_Write
 * 写入全局设置(一般用于保存设置，ID格式一般为：ext_[扩展名称]_[作者名称])
 * ID 全局设置项
 * SECTION 设置节
 * DELID 是否删除项
 * DATA 写入的数据
 * DELSE 是否删除节
 * 返回 写入成功返回TRUE，失败返回FALSE
 */
Api(bool, Global_Write, const char* ID, const char* SECTION, bool DELID, const char* DATA, bool DELSE);

/*
 * Global_Get
 * 获取全局设置数据
 * ID 全局设置项
 * SECTION 设置节
 * DEFAULT 默认返回(指定项目不存在时返回此数据)
 * 返回 取到的数据
 */
Api(const char*, Global_Get, const char* ID, const char* SECTION, const char* DEFAULT);

/*
 * Global_ALLSECTION
 * 获取指定项所有节
 * ID 全局设置项
 * 返回 所有节以CGJson格式返回，可直接使用Json解析
 */
Api(const char*, Global_ALLSECTION, const char* ID);

/*
 * UserData_Write
 * 写入用户属性设置(一般用于保存指定用户和修改用户一些属性设置)
 * UserID 用户ID
 * SECTION 用户属性设置节
 * DELID 是否删除项
 * DATA 写入的数据
 * DELSE 是否删除节
 * 返回 写入成功返回TRUE，失败返回FALSE
 */
Api(bool, UserData_Write, const char* UserID, const char* SECTION, bool DELID, const char* DATA, bool DELSE);

/*
 * UserData_Get
 * 获取用户属性设置
 * UserID 用户ID
 * SECTION 用户属性设置节
 * DEFAULT 默认返回(指定项目不存在时返回此数据)
 * 返回 取到的数据
 */
Api(const char*, UserData_Get, const char* UserID, const char* SECTION, const char* DEFAULT);

/*
 * UserData_ALLSECTION
 * 获取指定用户所有节
 * UserID 用户ID
 * 返回 所有节以CGJson格式返回，可直接使用Json解析
 */
Api(const char*, UserData_ALLSECTION, const char* UserID);

/*
 * _get_map_attribute
 * 获取指定地图属性
 * mapname 地图名称
 * node 属性节名
 * 返回 取出的属性数据
 */
Api(const char*, _get_map_attribute, const char* mapname, const char* node);

/*
 * _judge_exist_user
 * 判断用户是否存在(已注册)
 * UserID 用户ID
 * 返回 存在返回TRUE，不存在返回FALSE
 */
Api(bool, _judge_exist_user, const char* UserID);

/*
 * _get_name_user
 * 获取指定用户的昵称
 * UserID 用户ID
 * 返回 返回用户昵称
 */
Api(const char*, _get_name_user, const char* UserID);

/*
 * _update_user_attribute
 * 更新用户指定的基础游戏属性
 * UserID 用户ID
 * attribute 属性字段名
 * value 更新后的数据
 * 返回 更新成功返回TRUE，失败返回FALSE
 */
Api(bool, _update_user_attribute, const char* UserID, const char* attribute, const char* value);

/*
 * _update_user_attribute_int
 * 更新用户指定的基础游戏属性
 * UserID 用户ID
 * attribute 属性字段名
 * value 更新后的数据
 * 返回 更新成功返回TRUE，失败返回FALSE
 */
Api(bool, _update_user_attribute_int, const char* UserID, const char* attribute, int32_t value);

/*
 * _update_user_attribute_long_int
 * 更新用户指定的基础游戏属性
 * UserID 用户ID
 * attribute 属性字段名
 * value 更新后的数据
 * 返回 更新成功返回TRUE，失败返回FALSE
 */
Api(bool, _update_user_attribute_long_int, const char* UserID, const char* attribute, int64_t value);

/*
 * _get_user_attribute
 * 获取用户指定的基础游戏属性
 * UserID 用户ID
 * attribute 属性字段名
 * error_ret 如果获取失败返回此数据
 * 返回 返回指定游戏属性值
 */
Api(const char*, _get_user_attribute, const char* UserID, const char* attribute, const char* error_ret);

/*
 * _get_user_attribute_int
 * 获取用户指定的基础游戏属性
 * UserID 用户ID
 * attribute 属性字段名
 * error_ret 如果获取失败返回此数据
 * 返回 返回指定游戏属性值
 */
Api(int32_t, _get_user_attribute_int, const char* UserID, const char* attribute, int32_t error_ret);

/*
 * _get_user_attribute_long_int
 * 获取用户指定的基础游戏属性
 * UserID 用户ID
 * attribute 属性字段名
 * error_ret 如果获取失败返回此数据
 * 返回 返回指定游戏属性值
 */
Api(int64_t, _get_user_attribute_long_int, const char* UserID, const char* attribute, int64_t error_ret);

/*
 * _get_goods_json
 * 获取指定物品的属性Json数据
 * goods 物品名称
 * 返回 返回Json数据
 */
Api(const char*, _get_goods_json, const char* goods);

/*
 * _judge_exist_goods
 * 判断指定物品是否存在
 * goods 物品名称
 * id 物品快捷码(goods与id只需选择一个填写，剩下一个留空文本即可)
 * 返回 存在返回TRUE，失败返回FALSE
 */
Api(bool, _judge_exist_goods, const char* goods, const char* id);

/*
 * _get_goods_type
 * 获取指定物品的类型
 * goods 物品名称
 * 返回 物品类型名称
 */
Api(const char*, _get_goods_type, const char* goods);

/*
 * _judge_lock_goods
 * 判断物品是否锁定
 * goods 物品名称
 * 返回 锁定返回TRUE，非锁定返回FALSE
 */
Api(bool, _judge_lock_goods, const char* goods);

/*
 * _update_knapsack_add
 * 给指定用户的背包添加物品
 * UserID 用户ID
 * goods 物品名称
 * quantity 添加数量(可为负数)
 * del 是否删除此物品
 * 返回 成功返回TRUE，失败返回FALSE
 */
Api(bool, _update_knapsack_add, const char* UserID, const char* goods, int32_t quantity, bool del);

/*
 * _update_knapsack_add
 * 给指定用户的背包添加物品
 * UserID 用户ID
 * goods 物品名称
 * quantity 物品消耗数量
 * isRelation 是否进行关联消耗
 * 返回 成功此物品剩余数量
 */
Api(int32_t, _update_knapsack_consume, const char* UserID, const char* goods, int32_t quantity, bool isRelation);

/*
 * _get_knapsack_all
 * 取指定用户背包所有物品(不受筛选影响)
 * UserID 用户ID
 * _lock 是否不取锁定物品
 * 返回 成功返回记录集句柄，失败返回0
 */
Api(void*, _get_knapsack_all, const char* UserID, bool _lock);

/*
 * _get_knapsack_all_cgjson
 * 取指定用户背包所有物品(不受筛选影响)
 * UserID 用户ID
 * _lock 是否不取锁定物品
 * 返回 成功返回物品CGJson数据
 */
Api(const char*, _get_knapsack_all_cgjson, const char* UserID, bool _lock);

/*
 * _get_knapsack_filter_all
 * 取指定用户背包所有物品(受筛选影响)
 * UserID 用户ID
 * _lock 是否不取锁定物品
 * 返回 成功返回记录集句柄，失败返回0
 */
Api(int32_t, _get_knapsack_filter_all, const char* UserID, bool _lock);

/*
 * _get_knapsack_filter_all_cgjson
 * 取指定用户背包所有物品(受筛选影响)
 * UserID 用户ID
 * _lock 是否不取锁定物品
 * 返回 成功返回物品CGJson数据
 */
Api(const char*, _get_knapsack_filter_all_cgjson, const char* UserID, bool _lock);

/*
 * _get_knapsack_quantity
 * 取指定用户背包指定物品数量
 * UserID 用户ID
 * goods 物品名称
 * 返回 返回物品数量整数
 */
Api(int32_t, _get_knapsack_quantity, const char* UserID, const char* goods);

/*
 * _judge_exist_msgtem
 * 判断指定消息模板是否存在
 * Name 消息模板名称
 * 返回 如果存在返回TRUE,不存在返回FALSE
 */
Api(bool, _judge_exist_msgtem, const char* Name);

/*
 * _update_msgtem
 * 修改指定消息模板数据，如果不存在则新加一条消息模板
 * Name 消息模板名称
 * data 写入的消息模板数据
 * 返回 写入成功返回TRUE，失败返回FALSE
 */
Api(bool, _update_msgtem, const char* Name, const char* data);

/*
 * _get_msgtem
 * 获得指定消息模板数据
 * Name 消息模板名称
 * 返回 返回消息模板文本数据
 */
Api(const char*, _get_msgtem, const char* Name);

/*
 * _get_user_power
 * 获得指定用户的权限值
 * UserID 用户ID
 * 返回 整数权限值
 */
Api(int32_t, _get_user_power, const char* UserID);

/*
 * _update_user_power
 * 更新指定用户的权限值
 * UserID 用户ID
 * power_val 权限值
 * 返回 成功返回TRUE,失败返回FALSE
 */
Api(bool, _update_user_power, const char* UserID, int32_t power_val);

/*
 * _get_user_real_atk
 * 取玩家真实攻击力
 * UserID 用户ID
 * type 攻击类型
 */
Api(int32_t, _get_user_real_atk, const char* UserID, int32_t type);

/*
 * _get_user_real_def
 * 取玩家真实防御力
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_def, const char* UserID);

/*
 * _get_user_real_mag
 * 取玩家真实魔抗力
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_mag, const char* UserID);

/*
 * _get_user_real_cri
 * 取玩家真实暴击率
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_cri, const char* UserID);

/*
 * _get_user_real_dod
 * 取玩家真实闪避率
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_dod, const char* UserID);

/*
 * _get_user_real_hit
 * 取玩家真实命中率
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_hit, const char* UserID);

/*
 * _get_user_real_uhp
 * 取玩家真实上限生命
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_uhp, const char* UserID);

/*
 * _get_user_real_ump
 * 取玩家真实上限魔法
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_ump, const char* UserID);

/*
 * _get_user_real_ahp
 * 取玩家真实吸血比
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_ahp, const char* UserID);

/*
 * _get_user_real_imd
 * 取玩家真实免伤比
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_imd, const char* UserID);

/*
 * _get_user_real_dpv
 * 取玩家真实物穿值
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_dpv, const char* UserID);

/*
 * _get_user_real_dpr
 * 取玩家真实物穿比
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_dpr, const char* UserID);

/*
 * _get_user_real_ptv
 * 取玩家真实法穿值
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_ptv, const char* UserID);

/*
 * _get_user_real_ptr
 * 取玩家真实法穿比
 * UserID 用户ID
 */
Api(int32_t, _get_user_real_ptr, const char* UserID);

/*
 * _judge_exist_union
 * 判断公会是否存在
 * _unionName 公会名称
 * 返回 如果存在返回TRUE，不存在返回FALSE
 */
Api(bool, _judge_exist_union, const char* _unionName);

/*
 * _union_write_set
 * 写公会属性设置
 * _unionName 公会名称
 * node 节名称
 * data 写入数据
 * 返回 如果成功返回TRUE，失败返回FALSE
 */
Api(bool, _union_write_set, const char* _unionName, const char* node, const char* data);

/*
 * _union_get_set
 * 取公会属性设置
 * _unionName 公会名称
 * node 节名称
 * 返回 返回取到的公会设置数据文本
 */
Api(const char*, _union_get_set, const char* _unionName, const char* node);

/*
 * _union_get_attributes
 * 取公会属性数据
 * _unionName 公会名称
 * node 节名称
 * 返回 返回取到的公会属性数据文本
 */
Api(const char*, _union_get_attributes, const char* _unionName, const char* node);

/*
 * _union_set_attributes
 * 写公会属性数据
 * _unionName 公会名称
 * node 节名称
 * data 写入数据
 * 返回 如果成功返回TRUE，失败返回FALSE
 */
Api(bool, _union_set_attributes, const char* _unionName, const char* node, const char* data);

/*
 * _union_add_exp
 * 增加公会经验
 * _unionName 公会名称
 * exp 增加的经验数量
 * 返回 如果成功返回TRUE，失败返回FALSE
 */
Api(bool, _union_add_exp, const char* _unionName, int64_t exp);

/*
 * CGJson关键词转义
 */
Api(const char*, _CGJson_Escape, const char* Text);

/*
 * CGJson关键词反转义
 */
Api(const char*, _CGJson_BackEscape, const char* Text);

/*
 * CG_event_join
 * 向CakeGame发送事件指令
 * event_data 事件数据(CGJson)
 */
Api(void, CG_event_join, const char* event_data);

/*
 *_dynamic_attributes_register
 * 注册一个动态属性
 * user 注册对象
 * AttName 属性名称
 * value 动态属性值
 * AttInvalidTime 失效时间
 */
Api(int32_t, _dynamic_attributes_register, const char* user, const char* AttName, int32_t value, const char* AttInvalidTime);

/*
 * _dynamic_attributes_sum
 * 获取指定用户与类型的有效动态属性值总和
 * user 指定用户
 * AttName 属性名称
 */
Api(int32_t, _dynamic_attributes_sum, const char* user, const char* AttName);

/*
 * _dynamic_attributes_delete
 * 删除指定动态属性
 * Id 欲删除的动态属性Id
 */
Api(bool, _dynamic_attributes_delete, int32_t Id);

/*
 * _custom_attributes_register
 * 注册一个自定属性
 * SQL 自定属性计算SQL
 */
Api(int32_t, _custom_attributes_register, const char* SQL);

/*
 * _custom_attributes_delete
 * 删除一个自定属性
 * Id 欲删除的自定属性Id
 */
Api(bool, _custom_attributes_delete, int32_t Id);
