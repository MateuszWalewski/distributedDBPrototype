import sys
import pytest
sys.path.insert(1, '/home/guest1/engine/')

from initDB import IntColumn

@pytest.fixture(scope="module")
def start_up():
    a = IntColumn()
    a.LoadData("/home/guest1/engine/src/data1.csv")
    yield a

@pytest.fixture(scope="module")
def tear_down():
    a = None


def testSum(start_up):
    a = start_up
    assert a.Sum() == 80
