#include "pch.h"

#include "PracticeCPP/MessagesOrder.h"
#define main() MAIN_ENTRY(MessagesOrder)

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Message {
public:
	Message(int idx, const string & text)
		: m_idx(idx)
		, m_text(text)
	{}
	
	const string& get_text() { return m_text; }
	int getIdx() { return m_idx; }

	bool operator< (const Message& msg2)
	{
		return m_idx < msg2.m_idx;
	}

private:
	string	m_text;
	int		m_idx;
};

class MessageFactory {
public:
	MessageFactory()
		: m_idx(0)
	{}

	Message create_message(const string& text)
	{
		return Message(m_idx++, text);
	}

private:
	int m_idx;
};

class Recipient {
public:
	Recipient() {}
	void receive(const Message& msg) {
		messages_.push_back(msg);
	}
	void print_messages() {
		fix_order();
		for (auto& msg : messages_) {
			cout << msg.get_text() << endl;
		}
		messages_.clear();
	}
private:
	void fix_order() {
		sort(messages_.begin(), messages_.end());
	}
	vector<Message> messages_;
};

class Network {
public:
	static void send_messages(vector<Message> messages, Recipient& recipient) {
		// simulates the unpredictable network, where sent messages might arrive in unspecified order
		random_shuffle(messages.begin(), messages.end());
		for (auto msg : messages) {
			recipient.receive(msg);
		}
	}
};

int main()
{
	MessageFactory message_factory;
	Recipient recipient;
	vector<Message> messages;
	string text;
	while (getline(cin, text)) {
		messages.push_back(message_factory.create_message(text));
	}
	Network::send_messages(messages, recipient);
	recipient.print_messages();

	return EXIT_SUCCESS;
}