#pragma once



class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY);
	~AActor();

	virtual void BeginPlay();
	virtual void Tick(int KeyCode);
	virtual void Render();//=0 순수가상함수-> 메인함수에서 인터페이스 강제/

	//accessor
	inline int GetX() const { return X; }
	inline int GetY() const { return Y; }

	inline void SetX(int NewX) { X = NewX; }
	inline void SetY(int NewY) { Y = NewY; }

	virtual bool operator<(const AActor& RHS) const
	{
		return this->SortOrder < RHS.SortOrder;
	}

	int SortOrder;
	bool bCollide;

protected:
	int X;
	int Y;
	


	char Shape;


private:

};

