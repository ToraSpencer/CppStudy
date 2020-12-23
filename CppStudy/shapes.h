#ifndef SHAPES_H_
#define SHAPES_H_

#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>

#include <cstdio>

#define PI 3.14159




// .hpp�ļ�
/*
    1����Header Plus Plus �ļ�д��
    2����*.h���ƣ�hpp��C++����ͷ�ļ� ��
    3����VCL ר�õ�ͷ�ļ�,��Ԥ���롣
    4����һ��ģ�����ͷ�ļ���
    5��һ����˵��*.h����ֻ��������û��ʵ�֣���*.hpp������ʵ�ֶ��У����߿��Լ� ��.cpp��������
    6��*.h���������using namespace std����*.hpp�����ޡ�

    a)���ɰ���ȫ�ֶ����ȫ�ֺ���
    ����hpp����������Ϊ.h��������include�����Ե�hpp�ļ��д���ȫ�ֶ������ȫ�ֺ���������hpp�����������includeʱ����������ʱ���·����ض������Ҫ���������������Ҫȥ��ȫ�ֶ��󣬽�ȫ�ֺ�����װΪ��ľ�̬������

    b)��֮�䲻��ѭ������
    ��.h��.cpp�ĳ����У�����������߶����֮����ѭ�����ù�ϵʱ��ֻҪԤ����ͷ�ļ�������������������ɣ�

    c)����ʹ�þ�̬��Ա
    ��̬��Ա��ʹ��������������ຬ�о�̬��Ա������hpp�б�����뾲̬��Ա��ʼ�����룬����hpp������ĵ�includeʱ�������������ض������Ψ һ��������const static���ͳ�Ա����Ϊ��vs2003�У������������ڶ���ʱ��ʼ�����磺
*/




// ��ͷ�ļ�����OOP��ѧϰ�����麯���������ࣨ�ӿڣ�����̳С���̬��
//							�ؼ���virtual, final, override,
/*
**	�麯����
**			����virtual�ؼ������ε����Ա������
**			�����г�Ա�������Է�Ϊ���ࣺ
**					1. ϣ��ֱ�ӱ�����̳еĳ�Ա����
**					2. ϣ�����า�ǵĺ����������ֺ���һ�㶼���ó��麯����
**			ֻ�����еĺ�������ǰ���Լ�virtual�����ⲻ��ʹ�á�
**			��Ĺ��캯�������Լ�virtual�������������ԡ�
**			��ʹ�û���ָ��������һ���麯����ʱ��ִ�ж�̬�󶨡���ֻ�����е�ʱ�����֪��ִ�е����ĸ��汾���麯����ȡ����ָ��ָ����ʲô���͵Ķ���
**			����ϣ����̬�󶨵�ʱ�򣬿���ʹ���������������
**
**
**
**
**	���麯����
**			�����Ա��������֮���" = 0;" ��������һ�����麯����
**			���麯��һ�㲻д���塣
**			���麯�����������趨һ���ӿڣ���һ���淶�����ã��涨�����б���Ҫ��ʵ�����������
**
**	�����ࣨ�ӿڣ���
**			���д��麯�����࣬���ܱ�ʵ������
**			�����Ǹ��������ṩ�ӿڣ��̳�֮��������Ը�����Щ�ӿڡ�
**
**	��̬��
**			���ֳ���̬�ĸ���ԭ�������û�ָ��ľ�̬�����붯̬���Ͳ�ͬ��
**
**	override�ؼ��֣�c++11��
**			д��ĳ�����Ա��������֮�󣬱�־�ú��������˻����е�ͬ���麯����
**			��δ���ǳɹ�������ᱨ��
**
*/


/***************************************************************************
***************************************************************************/
// ǰ������(forward declaration)
 


/***************************************************************************
***************************************************************************/
// extern����


/***************************************************************************
***************************************************************************/
// extern������
 

/***************************************************************************
***************************************************************************/
// �Զ������������


// Shape�ࡪ������ͼ�εĳ������
/*. BC------------------------------------------------------------------------
**	Shape�ࡪ������ͼ�εĳ������
**	
**	������
**			�����˾�����״��ĳ�����࣬�����˻�����һЩ�ӿڡ�
*. EC------------------------------------------------------------------------
*/
class Shape
{
public: 
    virtual ~Shape(void) = default;                           // ��ðѻ��������������Ϊvirtual
    virtual float area(void) const;                      // ��ͼ�εı����
    virtual float volume(void) const;                    // ��ͼ�ε����
    virtual void shapeName(void) const = 0;             // ���ͼ�ε����ơ�
};				 
 

// Point��
/*. BC------------------------------------------------------------------------
**	 
**	
**	������
**			�����˾�����״��ĳ�����࣬�����˻�����һЩ�ӿڡ�
*. EC------------------------------------------------------------------------
*/
class Point:public Shape
{
public:
    // ��Ԫ
    friend std::ostream& operator<<(std::ostream&, const Point&);
    
    // ���졢����������
    Point(float = 0, float = 0);                    // !!!
    ~Point(void);
    
    // get/set����
    void set(float, float);
    float getX(void) const;
    float getY(void) const;

    // ���������� 
    virtual void shapeName(void) const;                   // дvirtual��Ϊ�����ѿ����ߣ��ú������̳е�ʱ��Ӧ�ñ���д���ǡ�

protected:
    // protected��Ա����
    float x,y;    

};



// Square��
/*. BC------------------------------------------------------------------------
**	 
**	
**	������
**			 
*. EC------------------------------------------------------------------------
*/
class Square:public Point
{
public:
    // ��Ԫ��
    friend std::ostream& operator<<(std::ostream&, const Square&);

    // ���졢����������
    Square(float = 0, float = 0, float = 0);
    ~Square(void);

    // get/set������
    float getLength(void) const;
    void setLength(float);

    // ����������
    virtual void shapeName(void) const;
    virtual float area(void) const;                       
 
protected:
    float length;

};



// Cube��
/*. BC------------------------------------------------------------------------
**	 
**	
**	������
**			 
*. EC------------------------------------------------------------------------
*/
class Cube: public Square
{
public:
    // ��Ԫ
    friend std::ostream& operator<<(std::ostream&, const Cube&);

    // ���졢��������
    Cube(float = 0, float = 0, float = 0);
    ~Cube(void);
    
    // get/set����

    // ��������
    virtual void shapeName(void) const;
    virtual float area(void) const;                       
    virtual float volume(void) const; 

protected:

};



 

/***************************************************************************
***************************************************************************/
// ����������
std::ostream& operator<<(std::ostream&, const Point&);
std::ostream& operator<<(std::ostream&, const Square&);
std::ostream& operator<<(std::ostream&, const Cube&);




/***************************************************************************
***************************************************************************/
// �Զ������ʵ�֣�
float Shape::area(void) const                      // ��ͼ�εı����
{
    return 0;
}



float Shape::volume(void) const                     // ��ͼ�ε����
{
    return 0;
}  



Point::Point(float x0, float y0):x(x0),y(y0)            // ʹ�ó�ʼ���б�����ʼ��
{

}


Point::~Point(void)
{
    std::cout << "A Point object has been eliminated." << std::endl;

}
 
void Point::set(float x0, float y0)
{
    this->x = x0;
    this->y = y0;      
}  



float Point::getX(void) const
{   
    return this->x;

}



float Point::getY(void) const
{
    return this->y;
}



void Point::shapeName(void) const
{
    std::cout << "this is a point." << std::endl;
}




Square::Square(float x0, float y0, float length0):Point(x0, y0),length(length0)
{}


Square::~Square(void)
{
    std::cout << "A Square object has been eliminated." << std::endl;
}


float Square::getLength(void) const
{
    return this->length;
}

void Square::setLength(float length0)
{
    length = length0;

}
 
void Square::shapeName(void) const
{
    std::cout << "This is a square." << std::endl;
}

float Square::area(void) const
{   
    return (this->length)*(this->length);
}


Cube::Cube(float x0, float y0, float length0):Square(x0,y0,length0)
{

}

Cube::~Cube(void)
{
    std::cout << "A Cube object has been eliminated." << std::endl;
}

void Cube::shapeName(void) const
{
    std::cout << "This is a cube." << std::endl;

}

float Cube::area(void) const
{
    return (this->length)*(this->length);
}

float Cube::volume(void) const
{
    return (this->area())*(this->length);
}




/***************************************************************************
***************************************************************************/
// ������ʵ�֣�
std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p.x <<", " << p.y <<")";
    return os;

}



std::ostream& operator<<(std::ostream& os, const Square& s)
{
    os << "(" << s.x <<", " << s.y <<")" << "; length == " << s.length;
    return os;
}



std::ostream& operator<<(std::ostream& os, const Cube& c)
{
    os << "(" << c.x <<", " << c.y <<")" << "; length == " << c.length;
    return os;
}



#endif		// VECTOR_HPP_