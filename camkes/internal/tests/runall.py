#!/usr/bin/env python
# -*- coding: utf-8 -*-

#
# Copyright 2015, NICTA
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(NICTA_BSD)
#

from __future__ import absolute_import, division, print_function, \
    unicode_literals

import os, sys, unittest

ME = os.path.abspath(__file__)

from lint import TestLint
from lintsource import TestSourceLint
from testcachea import TestCacheA
from testcacheb import TestCacheB
from testfilehash import TestFileHash
from testfrozendict import TestFrozenDict
from testsqlsource import TestSQLSource
from teststrhash import TestStringHash

if __name__ == '__main__':
    unittest.main()