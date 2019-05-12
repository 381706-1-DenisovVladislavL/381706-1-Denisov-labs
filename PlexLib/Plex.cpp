#include "Plex.h"

TPlex::TPlex()
{
	right = NULL;
	left = NULL;
}

TPlex::TPlex(TPoint *_right, TPoint *_left)
{
	right = _right;
	left = _left;
}

TPlex::TPlex(TPlex& plex)
{
	TPlex *tmp1, *tmp2;
	tmp1 = dynamic_cast <TPlex*> (plex.left);
	tmp2 = dynamic_cast <TPlex*> (plex.right);
	if (tmp1 != 0) //создаем плекс
		left = new TPlex(*tmp1);
	else
		left = new TPoint(*plex.left);
	if (tmp2 != 0) //создаем плекс
		right = new TPlex(*tmp2);
	else
		right = new TPoint(*plex.right);
}

void TPlex::Add(TPoint *_right, TPoint *_left)
{
	if (right == 0 && left == 0) //если плекс пустой
	{
		right = _right;
		left = _left;
	}
	else //если уже что-то содержит
	{
		TStackList <TPoint*> point;
		TStackList <TPlex*> plex;
		point.Put(right);
		point.Put(left);
		plex.Put(this);
		plex.Put(this);
		bool flag = true;
		while (flag && (!point.IsEmpty() || !plex.IsEmpty()))
		{
			TPoint *t = point.Get();
			TPlex *p = dynamic_cast <TPlex*> (t);
			TPlex *par = plex.Get();
			if (t->GetX() == _right->GetX() && t->GetY() == _right->GetY())
			{
				if (par->left == t)
					par->left = new TPlex(_left, _right);
				else
					par->right = new TPlex(_left, _right);
				flag = false;
			}
			else if (t->GetX() == _left->GetX() && t->GetY() == _left->GetY())
			{
				if (par->left == t)
					par->left = new TPlex(_right, _left);
				else
					par->right = new TPlex(_right, _left);
				flag = false;
			}
			else if (p != 0)
			{
				point.Put(p->left);
				point.Put(p->right);
				plex.Put(p);
				plex.Put(p);
			}
		}
		if (flag)
			throw TException("Error line");
	}
}

TPoint* TPlex::GetRight()
{
	return right;
}

TPoint* TPlex::GetLeft()
{
	return left;
}

void TPlex::SetRight(TPoint *_right)
{
	right = _right;
}

void TPlex::SetLeft(TPoint *_left)
{
	left = _left;
}

TPoint* TPlex::Show(TPlex *p)
{
	if (p->right == 0 && p->left == 0)
		throw TException("Plex is empty");
	TPlex *pl, *pr;
	TPoint *tl, *tr;
	TPoint *pp = NULL;
	pl = dynamic_cast<TPlex*>(p->left);
	pr = dynamic_cast<TPlex*>(p->right);
	if (pl != 0) //если не дошли до точки, то имеем дело с плексом
		tl = Show(pl);
	else
		tl = p->left;
	if (pr != 0)
		tr = Show(pr);
	else
		tr = p->right;
	TLine A(tl, tr);
	A.Show();
	return tl;
}

void TPlex::Show()
{
	if (right == 0 && left == 0)
		throw TException("Plex is empty");
	TStackList<TPlex*> stack;
	TStackList<TPoint*> point;
	TPlex *pl, *pr;
	TPlex *p = this;
	TPoint *tl = NULL, *tr = NULL;
	stack.Put(p);
	while (!stack.IsEmpty())
	{
		p = stack.Get();
		while (tr == NULL)
		{
			pr = dynamic_cast<TPlex*>(p->right);
			pl = dynamic_cast<TPlex*>(p->left);
			if (pr != 0 && pl != 0)
			{
				if (point.GetTop() % 2 == 0)
					p = stack.Get();
				else if (point.GetTop() == 1)
				{
					tr = point.Get();
					tl = point.Get();
				}
				else
				{
					stack.Put(p);
					stack.Put(pr);
					stack.Put(p);
					p = dynamic_cast<TPlex*>(pl);
				}
			}
			else if (pr != NULL) //плекс, помещаем в стек
			{
				stack.Put(p);
				p = dynamic_cast<TPlex*>(pr);
			}
			else
			{
				tr = p->right;
			}
		}
		if (tl == NULL)
		{
			pl = dynamic_cast<TPlex*>(p->left);
			if (pl != NULL) //снова плекс, помещаем стек и переходим к новому плексу
			{
				stack.Put(p);
				p = dynamic_cast<TPlex*>(pl);
				tr = NULL;
				stack.Put(p);
			}
			else
			{
				tl = p->left;
			}
		}
		if (tr != NULL && tl != NULL)
		{

			TLine A(tl, tr);
			A.Show();
			if (!stack.IsEmpty())
			{
				p = stack.Get();
				pr = dynamic_cast<TPlex*>(p->right);
				pl = dynamic_cast<TPlex*>(p->left);
				TPoint *pp = tl;
				if (pr != 0 && pl != 0)
				{
					point.Put(pp);
					tl = NULL;
					tr = NULL;
				}
				else if (pr != 0)
				{
					tr = pp;
					tl = NULL;
				}
				else
				{
					tl = pp;
					tr = NULL;
				}
				stack.Put(p);
			}
		}
	}
}