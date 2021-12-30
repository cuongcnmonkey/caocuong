#include "DiemCao.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include"network/HttpRequest.h"
#include"network/HttpClient.h"
#include"network/HttpResponse.h"

using namespace rapidjson;

USING_NS_CC;

Scene* DiemCao::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = DiemCao::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool DiemCao::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }


    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();



    auto backgroundSprite = Sprite::create("background_1.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(backgroundSprite);

    this->Score();

    return true;
}

void DiemCao::Score() {
//    network::HttpRequest* request = new network::HttpRequest();
//    request->setRequestType(network::HttpRequest::Type::GET);
//    request->setUrl("https://onetconnectjunior.firebaseio.com/leaderboard.json");
//    request->setResponseCallback([=](network::HttpClient* sender, network::HttpResponse* response) {
//        rapidjson::Document doc;
//        if (200 == response->getResponseCode()) // connect success
//        {
//            std::vector<char>* buffer = response->getResponseData();
//
//            std::string data = std::string(buffer->begin(), buffer->end());
//
//            if (data.empty()) {
//                return;
//            }
//
//
//            doc.Parse<rapidjson::ParseFlag::kParseStopWhenDoneFlag>((char*)data.c_str());
//            if (doc.IsArray() && !doc.IsNull())
//            {
//                auto dataValue = doc.GetArray();
//
//                for (int i = 0; i < dataValue.Size(); i++)
//                {
//                    if (dataValue[i].IsObject() && !dataValue[i].IsNull())
//                    {
//                        auto value = dataValue[i].GetObjectW();
//
//                        if (value["name"].IsString() && !value["name"].IsNull() && value["score"].IsInt() && !value["score"].IsNull())
//                        {
//                            auto name = value["name"].GetString();
//                            int score = value["score"].GetInt();
//                            LeaderBoardInfo player(name, score);
//                            Leader.push_back(player);
//                        }
//                    }
//                }
//
//            }
//            Leader = SortScore(Leader);
//            std::string s = Leader.back().m_name;
//            auto mainMenu = CSLoader::getInstance()->createNode("csb/leader_board.csb");
//            this->addChild(mainMenu);
//            //auto name = mainMenu->getChildByName<ui::Text*>("name");
//
//            if (auto textName = cocos2d::utils::findChild<cocos2d::ui::Text*>(mainMenu, "name"))
//            {
//                textName->setString(Leader.back().m_name);
//            }
//            if (auto textName = cocos2d::utils::findChild<cocos2d::ui::Text*>(mainMenu, "score"))
//            {
//                std::string s = std::to_string((Leader.back().m_score));
//                textName->setString(s);
//            }
//            /*auto layout_1 = cocos2d::utils::findChild<cocos2d::ui::Layout*>(mainMenu, "panel")->clone();
//            for (int i = 0; i < 3; i++)
//            {
//                auto layout_1 = cocos2d::utils::findChild<cocos2d::ui::Layout*>(mainMenu, "panel")->clone();
//            }*/
//
//            auto listView = utils::findChild<ui::ListView*>(mainMenu, "listview");
//
//            for (int i = 0; i < 5; i++)
//            {
//                auto layout = cocos2d::utils::findChild<cocos2d::ui::Layout*>(mainMenu, "panel")->clone();
//
//                if (auto name = utils::findChild<ui::Text*>(layout, "name"))
//                {
//                    name->setString("Thang ngao");
//                }
//
//                listView->pushBackCustomItem(layout);
//            }
//        }
//        else // connect failed
//        {
//        }
//        });
//    request->setTag("Get test");
//    network::HttpClient::getInstance()->send(request);
//    request->release();
//    return true;
//}

	network::HttpRequest* request = new network::HttpRequest();
	request->setRequestType(network::HttpRequest::Type::GET);
	request->setUrl("https://isschool.firebaseio.com/leaderboard.json");
	request->setResponseCallback([=](network::HttpClient* sender, network::HttpResponse* response) {
		rapidjson::Document doc;
		if (200 == response->getResponseCode()) // connect success
		{
			std::vector<char>* buffer = response->getResponseData();

			std::string data = std::string(buffer->begin(), buffer->end());

			if (!data.empty())
			{
				CCLOG("data:%s", data.c_str());
			}






			doc.Parse<rapidjson::ParseFlag::kParseStopWhenDoneFlag>((char*)data.c_str());
			if (doc.IsArray() && !doc.IsNull())
			{
				auto dataValue = doc.GetArray();

				for (int i = 0; i < dataValue.Size(); i++)
				{
					if (dataValue[i].IsObject() && !dataValue[i].IsNull())
					{
						auto value = dataValue[i].GetObjectW();

						if (value["name"].IsString() && !value["name"].IsNull() && value["score"].IsInt() && !value["score"].IsNull())
						{
							auto name = value["name"].GetString();
							int score = value["score"].GetInt();
							auto label = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 24);
							label->setPosition(Point(1126 / 2, 768 / 2));
							this->addChild(label, 1);
						}
					}
				}

			}





		}







		else // connect failed
		{
		}


		});


	
//	auto label = Label::createWithTTF(str, "fonts/Marker Felt.ttf", 24);
//	label->setPosition(Point(1126 / 2, 768 / 2));
//	this->addChild(label, 1);





	request->setTag("Get test");
	network::HttpClient::getInstance()->send(request);
	request->release();
}