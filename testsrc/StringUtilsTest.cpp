#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    
}

TEST(StringUtilsTest, Capitalize){
    EXPECT_EQ(StringUtils::Capitalize("hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::Capitalize("HELLO"),std::string("HELLO"));
    EXPECT_EQ(StringUtils::Capitalize(" hello"),std::string(" hello"));
    EXPECT_EQ(StringUtils::Capitalize("HELLO WORLD"),std::string("Hello World"));
    EXPECT_EQ(StringUtils::Capitalize("hello world"),std::string("Hello world"));
}

TEST(StringUtilsTest, Upper){
    EXPECT_EQ(StringUtils::Upper("heya"),std::string("HEYA"));
}

TEST(StringUtilsTest, Lower){
    EXPECT_EQ(StringUtils::Lower("HEYYA"),std::string("heyya"));
}

TEST(StringUtilsTest, LStrip){
    EXPECT_EQ(StringUtils::LStrip("   howdy  "),std::string("howdy  "));
}

TEST(StringUtilsTest, RStrip){
    EXPECT_EQ(StringUtils::RStrip("   howdy  "),std::string("   howdy"));
}

TEST(StringUtilsTest, Strip){
    EXPECT_EQ(StringUtils::Strip("   howdy  "),std::string("howdy"));
}

TEST(StringUtilsTest, Center){
    EXPECT_EQ(StringUtils::Center("hi",6),std::string("  hi  "));
    EXPECT_EQ(StringUtils::Center("hi",5),std::string(" hi  "));
    EXPECT_EQ(StringUtils::Center("money",7,'$'),std::string("$money$"));
    EXPECT_EQ(StringUtils::Center("over",2,'*'),std::string("over"));
}

TEST(StringUtilsTest, LJust){
    EXPECT_EQ(StringUtils::LJust("mu",3),std::string("mu "));
    EXPECT_EQ(StringUtils::LJust("mu",5),std::string("mu   "));
}

TEST(StringUtilsTest, RJust){
    EXPECT_EQ(StringUtils::RJust("mu",3),std::string(" mu"));
    EXPECT_EQ(StringUtils::RJust("mu",4),std::string("mu  "));
}

TEST(StringUtilsTest, Replace){
    EXPECT_EQ(StringUtils::Replace("the quick brown fox jumped over the lazy dog","the","no"),std::string("no quick brown fox jumped over no lazy dog"));
}

TEST(StringUtilsTest, Split){
    EXPECT_EQ(StringUtils::Split("the,quick,brown,fox",","),std::vector<std::string>({"the","quick","brown","fox"}));
    EXPECT_EQ(StringUtils::Split(" the, quick, brown, fox",",",std:vector<std::string>({" the"," quick"," brown"," fox"})));
}

TEST(StringUtilsTest, Join){
    EXPECT_EQ(StringUtils::Join(std::vector<std::string>({"the","quick","brown","fox"})," "),std::string("the quick brown fox"));
}

TEST(StringUtilsTest, ExpandTabs){
    EXPECT_EQ(StringUtils::ExpandTabs("the\tquick\tbrown\tfox",1),std::string("the quick brown fox"));
    EXPECT_EQ(StringUtils::ExpandTabs("the\tquick\tbrown\tfox",4),std::string("the quick   brown   fox"));
}

TEST(StringUtilsTest, EditDistance){
    EXPECT_EQ(StringUtils::EditDistance("the","quick","brown","fox"),4);
}
