#ifndef DEMO_RECORDER
#define DEMO_RECORDER

#include <vector>
#include <fstream>

#include "Demo.h"
#include "Game/Player.h"
#include "Game/Team.h"

/**
@brief Used to record demos
 */
class CDemoRecorder : public CDemo
{
public:
	CDemoRecorder();
	~CDemoRecorder();

	void SaveToDemo(const unsigned char* buf,const unsigned length);
	
	/**
	@brief assign a map name for the demo file
	When this function is called, we can rename our demo file so that
	map name / game time are visible. The demo file will be renamed by the
	destructor. Otherwise the name unnamed.sdf will be used.
	*/
	void SetName(const std::string& mapname);

	void SetGameID(const unsigned char* buf);
	void SetTime(int gameTime, int wallclockTime);

	void InitializeStats(int numPlayers, int numTeams, int winningAllyTeam);
	void SetPlayerStats(int playerNum, const CPlayer::Statistics& stats);
	void SetTeamStats(int teamNum, const std::list< CTeam::Statistics >& stats);

private:
	void WriteFileHeader();
	void WritePlayerStats();
	void WriteTeamStats();

	std::ofstream* recordDemo;
	std::string wantedName;
	std::vector< CPlayer::Statistics > playerStats;
	std::vector< std::vector<CTeam::Statistics> > teamStats;
};


#endif

