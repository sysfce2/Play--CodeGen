#include <boost/function.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/construct.hpp>

#include "Jitter_CodeGenFactory.h"

#include "Crc32Test.h"
#include "MultTest.h"
#include "RandomAluTest.h"
#include "RandomAluTest2.h"
#include "FpuTest.h"
#include "CompareTest.h"

typedef boost::function<CTest* ()> TestFactoryFunction;

TestFactoryFunction s_factories[] =
{
	TestFactoryFunction(boost::lambda::bind(boost::lambda::new_ptr<CCompareTest>())),
	TestFactoryFunction(boost::lambda::bind(boost::lambda::new_ptr<CRandomAluTest>(), true)),
	TestFactoryFunction(boost::lambda::bind(boost::lambda::new_ptr<CRandomAluTest>(), false)),
	TestFactoryFunction(boost::lambda::bind(boost::lambda::new_ptr<CRandomAluTest2>(), true)),
	TestFactoryFunction(boost::lambda::bind(boost::lambda::new_ptr<CRandomAluTest2>(), false)),
	TestFactoryFunction(boost::lambda::bind(boost::lambda::new_ptr<CCrc32Test>(), "Hello World!", 0x67FCDACC)),
	TestFactoryFunction(boost::lambda::bind(boost::lambda::new_ptr<CMultTest>(), true)),
	TestFactoryFunction(boost::lambda::bind(boost::lambda::new_ptr<CMultTest>(), false)),
	TestFactoryFunction(boost::lambda::bind(boost::lambda::new_ptr<CFpuTest>())),
	TestFactoryFunction(),
};

int main(int argc, char** argv)
{
	Jitter::CJitter jitter(Jitter::CreateCodeGen());
	TestFactoryFunction* currentTestFactory = s_factories;
	while(!currentTestFactory->empty())
	{
		CTest* test = (*currentTestFactory)();
		test->Compile(jitter);
		test->Run();
		delete test;
		currentTestFactory++;
	}
	return 0;
}
