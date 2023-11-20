#pragma once
#include <vector>
#include <string>

class UWorld;// ���漱��. has a


class SimpleEgine
{
public:
	
	virtual ~SimpleEgine();

	void Init();

	void Run();

	void Stop();


	void Term();

	void LoadLevel(std::string FileName);

	inline UWorld* GetWorld() const { return World; };//���漱��

	static SimpleEgine* GetInstance()
	{ 
		if (Instance == nullptr)
		{
			Instance = new SimpleEgine();
		}
		return Instance; 
	}//�̱�������

	

protected:

	
	UWorld* World;
	bool IsRunning;

	int Input();
	void Tick(int KeyCode);
	void Render();

	static SimpleEgine* Instance;

private:

	SimpleEgine();

};

#define GENGINE SimpleEgine::GetInstance()//define����� ��Ÿ���� �ڱ��ڽ��� ȣ��
