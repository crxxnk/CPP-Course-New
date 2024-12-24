#include <iostream>
#include <vector>
#include <map>
#include <memory>

enum class QuestState {
	AVAILABLE,
	IN_PROGRESS,
	COMPLETED,
	FAILED
};

enum class ObjectiveState {
	INCOMPLETE,
	COMPLETED
};

class QuestObjective
{
private:
	std::string description;
	ObjectiveState state;
public:
	QuestObjective(const std::string& desc): description(desc), state(ObjectiveState::INCOMPLETE) {}
	void complete() { state = ObjectiveState::COMPLETED; }
	ObjectiveState getState() const { return state; }
	std::string getDescription() const { return description; }
};

class Quest
{
private:
	std::string name;
	std::string description;
	QuestState state;
	std::vector<QuestObjective> objectives;
public:
	Quest(const std::string& questName, const std::string& questDesc): name(questName), description(questDesc), state(QuestState::AVAILABLE) {}
	void addObjective(const QuestObjective& objective) {
		objectives.push_back(objective);
	}
	void start() { state = QuestState::IN_PROGRESS; }
	void complete() { state = QuestState::COMPLETED; }

	QuestState getState() const { return state; }
	std::vector<QuestObjective>& getObjectives() { return objectives; }
	std::string getDescription() const { return description; }
	std::string getName() const { return name; }
};

class QuestManager
{
private:
	std::map<int, std::unique_ptr<Quest>> quests;
	int nextQuestID = 0;
public:
	int addQuest(const std::string& name, const std::string& description) {
		auto quest = std::make_unique<Quest>(name, description);
		int id = nextQuestID++;
		quests[id] = std::move(quest);
		return id;
	}
	Quest* getQuest(int questID) {
		if(quests.find(questID) != quests.end())
			return quests[questID].get();
		return nullptr;
	}
	void updateQuests() {
		for (auto& [id, quest] : quests) {
			if (quest->getState() == QuestState::IN_PROGRESS) {
				bool allCompleted = true;
				for (const auto& objective : quest->getObjectives()) {
					if (objective.getState() == ObjectiveState::INCOMPLETE) {
						allCompleted = false;
						break;
					}
				}
				if (allCompleted)
					quest->complete();
			}
		}
	}
};

int main()
{
	QuestManager questManager;
	int questID = questManager.addQuest("Hero's Journey", "Description");
	Quest* quest = questManager.getQuest(questID);
	if(quest) {
		quest->addObjective(QuestObjective("Kill 5 wolves"));
		quest->addObjective(QuestObjective("Speak to the villager"));
		quest->start();
	}

	if(quest) {
		auto& objectives = quest->getObjectives();
		for(auto& obj : objectives) {
			std::cout << "Objective: " << obj.getDescription() << std::endl;
			obj.complete();
		}
	}
	questManager.updateQuests();
	if(quest && quest->getState() == QuestState::COMPLETED)
		std::cout << "Quest '" << quest->getName() << "' completed!" << std::endl;

	return 0;
};