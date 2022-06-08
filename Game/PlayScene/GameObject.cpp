/*
ゲームオブジェクトのクラス
継承先->Player
	  ->Food
*/
#include "GameObject.h"

GameObject::GameObject()
	:mPos{}
{
}

GameObject::~GameObject()
{
}

std::deque<Int2> GameObject::GetPlayerPos()
{
	return std::deque<Int2>();
}

Int2 GameObject::GetPos()
{
	return Int2();
}

void GameObject::FalseFood()
{
}

Int2 GameObject::GetPos2()
{
	return Int2();
}

void GameObject::FalseFood2()
{
}

int GameObject::GetPlayerState()
{
	return 0;
}

// 尻尾の座標を渡す
std::deque<Int2> GameObject::GetTailPos()
{
	return std::deque<Int2>();
}

std::deque<Int2> GameObject::GetTailPos2()
{
	return std::deque<Int2>();
}

bool GameObject::GetTailState()
{
	return 0;
}

void GameObject::ChangeTailState()
{
}

int GameObject::GetTimer()
{
	return 0;
}

