### 参考
请参考官方文档：
https://www.sqlalchemy.org/

### SQLAlchemy 是什么
相当于 Java 的 Hibernate 和 Mybatis （我更喜欢MybatisPlus :），是 Python 里数一数二的 ORM框架。
ORM框架，本质上就是程序员懒得写 SQL 语句或者实体对象代码，于是让对象代码生成 SQL 语句或者让 SQL 语句生成对象，形成所谓的对象关系映射的程序框架（**Object Relational Mapping**)

### 初始化
初始化填好数据库信息，连接数据库，生成引擎，建立会话就好。当然它还可以连接内存数据库 sqlite 。
echo参数可以控制是否显示数据库操作细节。
```Python
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker
from sqlalchemy import create_engine
from sqlalchemy import Column, Integer, String

mysql_config = 'mysql+pymysql://%s:%s@%s:%s/%s?charset=utf8' % (username, password, host, port, database_name)
engine = create_engine(mysql_config, echo=False)
Base = declarative_base()
DbSession = sessionmaker(bind=engine, expire_on_commit=False)
session = DbSession()
```

通过 declarative_base ，框架会处理你的类声明，自动将你的类与数据库表绑定。
如下：User 继承 Base 。

最好在类内声明数据类型。 primary_key 参数代表是否为主键。
__tablename__ 为数据表表名。

```Python
class User(Base):
    __tablename__ = 'users'

    id = Column(Integer, primary_key=True)
    name = Column(String)
    fullname = Column(String)
    password = Column(String)
```

### 增加

```Python
user1 = User(name='lihua', age=18)
session.add(user1)

user2 = User(name='hanmeimei', age=18)
user3 = User(name='songwenhua', age=18)

session.add_all([user1, user2])
session.commit()
# commit 才能提交更改
```


### 查找

过滤器有 filter_by 和 filter ，前者用于简单的查询。
filter_by 只支持 = 运算。
filter 支持 ==, >, < ，还支持 like, has, in_, or_, and_ 等自带操作。
查找后要加 all(), first(), 或者 limit() 。
```Python
session.query(User).filter_by(id=1).first()
# 代表第一个
# desc(): 降序
session.query(User).order_by(User.id.desc()).all()
# asc()：升序
session.query(User).order_by(Users.name.desc(),User.id.asc()).all()

#	例子
query.filter(Address.user == someuser)
query.filter(Address.user != someuser)
query.filter(Address.user == None)
# 名称中包含
query.filter(User.addresses.contains(someaddress))
# 用于多对一关系
query.filter(User.addresses.any(Address.email_address == 'bar'))
```


### 删除


```Python
User.query.filter(User.id == 123).delete()
session.commit()
```


### 修改

只需要查找之后，修改对象的值，commit 就可以了。
```Python
p = session.query(ParamClass).filter_by(id=1).first()
p.k1 = k1
session.commit()
```

### flush 和 commit区别
flush 只是将语句发送到数据库内存，这种改变在这个会话可以看见，其他会话则不然。
commit 会提交所有更改，存至磁盘，其他会话也能查询到这种更改。

### 如何动态绑定表
接下来是重头戏了，由于业务需求，我需要根据情况，将同一类型的对象，存储在不同的表，也就是将数据存多个表，这些表的列名和结构都一致。
Python 的一个特性是可以动态生成类，利用 type() 不仅可以判断数据类型，还可以生成类：

> type(类名, 父类的元组（针对继承的情况，可以为空），包含属性的字典（名称和值）)

由于框架是根据__tablename__来绑定表的，而且类的__tablename__是无法改变的。
于是可以用字典在一开始就把表名和类相关联，Model 是存粹的数据模型，Base 是 declarative_base 而来。这样就可以根据情况来匹配类了。
```Python
class User():
    id = Column(Integer, primary_key=True)
    name = Column(String)
    fullname = Column(String)
    password = Column(String)

table_mapper_dict[table_name] = type(
	table_name,
	(Model, Base),
	{'__tablename__': table_name}
)
```
