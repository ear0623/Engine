#pragma once
#include <vector>
#include <string>

class UWorld;// 전방선언. has a


class SimpleEgine
{
public:
	
	virtual ~SimpleEgine();

	void Init();

	void Run();

	void Stop();


	void Term();

	void LoadLevel(std::string FileName);

	inline UWorld* GetWorld() const { return World; };//전방선언

	static SimpleEgine* GetInstance()
	{ 
		if (Instance == nullptr)
		{
			Instance = new SimpleEgine();
		}
		return Instance; 
	}//싱글턴패턴

	

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

#define GENGINE SimpleEgine::GetInstance()//define선언시 오타주의 자기자신을 호출
